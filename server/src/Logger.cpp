/**
 * @file Logger.cpp
 * @date 6 Feb 2022
 * @author Yury Loshmanov
 */
#include <iostream>
#include <fmt/format.h>

#include "../include/Logger.hpp"


void Logger::consoleLog(const std::string &message) {
    std::cout << fmt::format("LOG: {}", message) << std::endl;
}
