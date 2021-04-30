/*
** EPITECH PROJECT, 2021
** Automatic Precense
** File description:
** automatic_presence
*/

#ifndef AUTOMATIC_PRESENCE_HPP_
#define AUTOMATIC_PRESENCE_HPP_

/*!
 * \file filehandle.hpp
 * \author Nico
 * \brief Class Error
 * \version 1.0
*/

#include "filehandle.hpp"

/**
 * \class automatic_presence
 * \brief settings
 */
class automatic_presence
{
    private:
        std::string path;
        std::ofstream newfile;
        int time_rules_start = 0, time_rules_end = 0;
        int time_player_start = 0, time_player_end = 0;
        short late_authorized = 5;


        std::string email = "";
    public:
        ////////////////////////////////////////////////////////////
        ///
        /// \author Nico
        ///
        /// \date 18/04/21
        ///
        /// \version 1.0
        ///
        /// \fn void AutomaticPresence()
        ///
        /// \brief AutomaticPresence Handle
        ///
        ////////////////////////////////////////////////////////////
        void AutomaticPresence();

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
        automatic_presence(int nbArg, char **args);

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
        ~automatic_presence();
};

#endif /* !AUTOMATIC_PRESENCE_HPP_ */
