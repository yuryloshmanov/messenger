//
// Created by Yury Loshmanov on 06.02.2022.
//

#include <iostream>

#include "../include/Logger.hpp"


void Logger::log(const std::string &message) {
    // TODO: add std::format
    std::cout << "LOG: " << message << std::endl;
}
