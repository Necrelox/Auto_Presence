/*
** EPITECH PROJECT, 2021
** Automatic Precense
** File description:
** filehandle
*/

#include "filehandle.hpp"

void filehandle::verifFile_exist(const std::string &path)
{
    if (!std::filesystem::exists(path))
        throw CError("Error : File not exist.");
}

void filehandle::verifFile_empty(const std::string &path) const
{
    if (std::filesystem::is_empty(path))
        throw CError("Error : File is empty.");
}

filehandle::filehandle(std::string path)
{
    this->verifFile_exist(path);
    this->verifFile_empty(path);
    this->file.open(path, std::ios::in);
}

filehandle::~filehandle()
{
    this->file.close();
}