//
// Created by Yury Loshmanov on 06.02.2022.
//

#include <iostream>
#include <fmt/format.h>

#include "../include/Logger.hpp"


void Logger::log(const std::string &message) {
    std::cout << fmt::format("LOG: {}", message) << std::endl;
}
