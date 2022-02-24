/**
 * @file Logger.hpp
 * @date 6 Feb 2022
 * @author Yury Loshmanov
 */
#ifndef SERVER_LOGGER_HPP
#define SERVER_LOGGER_HPP

#include <string>


class Logger {
public:
    Logger() = default;

    static void consoleLog(const std::string &message);
};


#endif //SERVER_LOGGER_HPP
