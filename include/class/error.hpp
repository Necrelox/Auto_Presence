/*
** EPITECH PROJECT, 2021
** Automatic Precense
** File description:
** error
*/


#ifndef ERROR_HPP_ 
#define ERROR_HPP_

#include <string>
#include <exception>
#include <iostream>

/*!
 * \file error.hpp
 * \author Nico
 * \brief Class Error
 * \version 1.0
*/

/**
 * \class Core_Class_error inherits of class std::exception
 * \brief For throw a error with file and error message (can print help message)
 */

class CError : public std::exception
{
   public:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 18/04/21
        ///
        /// \version 1.0
        ///
        /// \fn CError(const std::string &error_msg)
        ///
        /// \brief Constructor
        ///
        /// \param[in] error_msg message of error
        ///
        ////////////////////////////////////////////////////////////
        CError(const std::string &error_msg);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 18/04/21
        ///
        /// \version 1.0
        ///
        /// \fn const std::string get_error_msg() const
        ///
        /// \brief Get error message
        ///
        /// \return Error message
        ///
        ////////////////////////////////////////////////////////////
        const std::string &get_error_msg() const;

    private:
        std::string _error_msg; /**< String contain error message*/

};


#endif /* !ERROR_HPP_ */