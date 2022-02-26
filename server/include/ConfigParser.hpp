/**
 * @file ConfigParser.hpp
 * @date 26 Feb 2022
 * @author Yury Loshmanov
 */
#ifndef SERVER_CONFIGPARSER_HPP
#define SERVER_CONFIGPARSER_HPP

#include <string>
#include <boost/json.hpp>


class ConfigParser {
public:
    ConfigParser(const std::string &configFilePath);
};


#endif //SERVER_CONFIGPARSER_HPP
