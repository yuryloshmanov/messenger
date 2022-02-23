/**
 * @file main.cpp
 * @date 2 Feb 2022
 * @author Yury Loshmanov
 */
#include <iostream>

#include "../include/Server.hpp"


int main() {
    try {
        Server::get().run();
    } catch (std::runtime_error &error) {
        std::cout << error.what() << std::endl;

        return 1;
    }

    return 0;
}
