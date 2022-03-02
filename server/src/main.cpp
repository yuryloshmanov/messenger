/**
 * @file main.cpp
 * @date 2 Feb 2022
 * @author Yury Loshmanov
 */
#include <iostream>

#include "../include/Server.hpp"
#include "../include/ConfigParser.hpp"
#include "../include/DatabaseProxy/PostgresqlProxy.hpp"


int main() {
    ConfigParser configParser;
    
    try {
        Server::setDatabaseProxyType<PostgresqlProxy>();
        Server::get().run();
    } catch (std::runtime_error &error) {
        std::cout << error.what() << std::endl;

        return 1;
    }

    return 0;
}
