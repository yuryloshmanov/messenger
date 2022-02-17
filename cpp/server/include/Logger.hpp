//
// Created by Yury Loshmanov on 06.02.2022.
//

#ifndef SERVER_LOGGER_HPP
#define SERVER_LOGGER_HPP

#include <string>


class Logger {
public:
    Logger() = default;

    static void consoleLog(const std::string &message);
};


#endif //SERVER_LOGGER_HPP
