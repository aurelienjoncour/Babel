/*
** EPITECH PROJECT, 2021
** B-CPP-500-REN-5-1-babel-aurelien.joncour
** File description:
** User Handler
*/

#ifndef USER_HANDLER_HPP
#define USER_HANDLER_HPP

#include <string>
#include <memory>

#include "DatabaseManager.hpp"
#include "User.hpp"

#define USER_TABLE_NAME "user"
#define USER_CONNECTED_TABLE_NAME "userConnected"

#define USER_PRIMARY_KEY_NAME "id"

namespace Babel::Server::Db {
    class UserHandler
    {
        public :
            UserHandler(const std::shared_ptr<DatabaseManager> dbManager);
            ~UserHandler();

            void addUser(const std::string &name) const;
            void removeUser(const std::string &name) const;

            User getUser(const std::string &name) const;

            void connectUser(const std::string &name) const;
            void disconnectUser(const std::string &name) const;

        protected:
        private:
            std::shared_ptr<DatabaseManager> _dbManager;
    };
}

#endif /* !USER_HANDLER_HPP */
