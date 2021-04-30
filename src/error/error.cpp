/*
** EPITECH PROJECT, 2021
** Automatic Precense
** File description:
** error
*/

#include "error.hpp"

const std::string &CError::get_error_msg() const
{
    return this->_error_msg;
}

CError::CError(const std::string &error_msg) : _error_msg(error_msg)
{
}