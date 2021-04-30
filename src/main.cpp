/*
** EPITECH PROJECT, 2021
** Automatic Precense
** File description:
** main
*/

#include "define.hpp"
#include "error.hpp"
#include "automatic_presence.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 4 || ac > 5)
            throw CError("Error number of arguments");
        else {
            automatic_presence presence(ac, av);
            presence.AutomaticPresence();
            return OK;
        }
    }
    catch(const CError& e)
    {
        std::cerr << e.get_error_msg() << '\n';
        if (ac < 4 || ac > 5)
            std::cout << "\nFor use Precense : \n\t./presence (file of meetingAttendanceReport by Teams) (Hour of start activity) (Hour of end activity) [limit late]" << std::endl;
    }
    return ERROR;
}