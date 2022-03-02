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
        Server::get().run();
        // TODO: Move endPoint to config file
        Server::setDatabaseProxy(std::make_unique<PostgresqlProxy>(configParser.getPostgresqlURL()));
    } catch (std::runtime_error &error) {
        std::cout << error.what() << std::endl;

        return 1;
    }

    return 0;
}
