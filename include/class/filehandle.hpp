/*
** EPITECH PROJECT, 2021
** Automatic Precense
** File description:
** filehandle
*/

#ifndef FILEHANDLE_HPP_
#define FILEHANDLE_HPP_

#include "error.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/stat.h>

/*!
 * \file filehandle.hpp
 * \author Nico
 * \brief Class Error
 * \version 1.0
*/

/**
 * \class filehandle
 * \brief manage the csv file
 */

class filehandle
{
    private:

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 18/04/21
        ///
        /// \version 1.0
        ///
        /// \fn void verifFile_empty(const std::string &path) const
        ///
        /// \brief Destructor
        ///
        ////////////////////////////////////////////////////////////
        void verifFile_empty(const std::string &path) const;

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 18/04/21
        ///
        /// \version 1.0
        ///
        /// \fn void verifFile_exist(const std::string &path)
        ///
        /// \brief Destructor
        ///
        ////////////////////////////////////////////////////////////
        void verifFile_exist(const std::string &path);
    public:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 18/04/21
        ///
        /// \version 1.0
        ///
        /// \fn filehandle(std::string path)
        ///
        /// \brief Constructor
        ///
        /// \param[in] path path to file
        ///
        ////////////////////////////////////////////////////////////
        filehandle(std::string path);

        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 18/04/21
        ///
        /// \version 1.0
        ///
        /// \fn ~filehandle()
        ///
        /// \brief Destructor
        ///
        ////////////////////////////////////////////////////////////
        ~filehandle();

        std::ifstream file;
};

#endif /* !FILEHANDLE_HPP_ */