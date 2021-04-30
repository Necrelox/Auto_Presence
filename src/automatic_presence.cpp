/*
** EPITECH PROJECT, 2021
** Automatic Precense
** File description:
** automatic_presence
*/

#include "automatic_presence.hpp"
#include "filehandle.hpp"
#include "tools.hpp"
#include <ctime>
#include <algorithm>
#include <iterator>

automatic_presence::automatic_presence(int nbArg, char **args)
{
    this->path = args[1];
    if (nbArg == 5)
        this->late_authorized = std::atoi(args[4]);
    time_t now = time(NULL);
    tm *date = localtime(&now);
    std::string NameNewFile = "presence-" + std::to_string(date->tm_mday) + ":" + std::to_string(date->tm_mon+1) + ":" + std::to_string(date->tm_year+1900) + ".txt";
    this->newfile.open(NameNewFile, std::ios::out);

    for (int i = 2; i < 4 ; i++) {
        std::string rules(args[i]);
        std::istringstream flux_rules(rules);
        std::string split_rules;
        int check = std::count(rules.begin(), rules.end(), ':');
        for (int t = 0, div = 10000; t < check+1; t++) {
            getline(flux_rules, split_rules, ':');

            split_rules.erase(std::remove(split_rules.begin(), split_rules.end(), 0), split_rules.end()); 
            for (size_t j = 0; j < split_rules.size() ; j++) {
                // std::cout << "[" << split_rules[j] << "] \n";
                if (!std::isdigit(split_rules[j]))
                    throw CError("Error argument");
            }

            if (i == 2)
                this->time_rules_start += std::atoi(split_rules.c_str()) * div;
            else
                this->time_rules_end += std::atoi(split_rules.c_str()) * div;
            div /= 100;
        }
    }
}

automatic_presence::~automatic_presence()
{
    this->newfile.close();
}

void automatic_presence::AutomaticPresence()
{
    filehandle handle(this->path);
    std::string buff;
    this->newfile << "login;present" << std::endl;
    while (std::getline(handle.file, buff)) {
        short count = std::count(buff.begin(), buff.end(), '\t');
        if (count == 5) {
            short valid = 0;
            std::stringstream manipule(buff);
            std::vector<std::string> tab;
            std::string push;
            while(getline(manipule, push, ' '))
                tab.push_back(push);

            int key = 0;
            this->time_player_start = 0;
            this->time_player_end = 0;
            for (size_t i = 0, check = 0; i < tab.size(); i++) {
                check = std::count(tab[i].begin(), tab[i].end(), ':');
                if (check == 2) {
                    std::istringstream flux_player(tab[i]);
                    std::string split_player;
                    for (int t = 0, div = 10000; t < 3; t++) {
                        getline(flux_player, split_player, ':');
                        split_player.erase(std::remove(split_player.begin(), split_player.end(), 0), split_player.end()); 
                        split_player.erase(split_player.begin() + 2, split_player.end());
                        for (size_t j = 0; j < split_player.size() ; j++)
                            if (!std::isdigit(split_player[j])) {
                                valid = 1;
                                break;
                            }
                        if (key == 0)
                            this->time_player_start += std::atoi(split_player.c_str()) * div;
                        else 
                            this->time_player_end += std::atoi(split_player.c_str()) * div;
                        div /= 100;

                        if (t == 0 && std::atoi(split_player.c_str()) > 24) {
                            valid = 1;
                            break;
                        }
                        if (t > 0 && std::atoi(split_player.c_str()) > 60) {
                            valid = 1;
                            break;
                        }
                    }
                    if (valid == 1) {
                        valid = 0;
                        break;
                    }
                    key++;
                }
                tab[i].erase(std::remove(tab[i].begin(), tab[i].end(), 0), tab[i].end()); 
                if (tab[i].find("@epitech.eu") != std::string::npos) {
                    tab[i].erase(0, tab[i].find("\t")+1);
                    tab[i].erase(tab[i].find("@epitech.eu")+11);
                    if (tab[i].find("\t") != std::string::npos)
                        tab[i].erase(0, tab[i].find("\t")+1);
                    this->email = tab[i];
                }
            }
            if (key == 2 && !this->email.empty() && this->time_player_start != 0 && this->time_player_end != 0) {
                this->newfile << this->email << ";";
                int presence = 1;
                int hour_p = this->time_player_start / 10000;
                int hour_r = this->time_rules_start / 10000;
                int min_p = (this->time_player_start - (hour_p * 10000))/100;
                int min_r = (this->time_rules_start - (hour_r * 10000))/100;

                if (hour_p <= hour_r) {
                    if (hour_p < hour_r) {
                        hour_p = hour_r;
                        min_p = min_r;
                    }
                    if (min_p > min_r + this->late_authorized)
                        presence = 0;
                }
                else
                    presence = 0;

                if (this->time_player_end < this->time_rules_end)
                    presence = 0;

                if (presence == 0)
                    this->newfile << "absent" << std::endl;
                else
                    this->newfile << "present" << std::endl;
            }

        }
    }
}