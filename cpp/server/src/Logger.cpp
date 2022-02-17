//
// Created by Yury Loshmanov on 06.02.2022.
//

#include <iostream>
#include <fmt/format.h>

#include "../include/Logger.hpp"


void Logger::consoleLog(const std::string &message) {
    std::cout << fmt::format("LOG: {}", message) << std::endl;
}
