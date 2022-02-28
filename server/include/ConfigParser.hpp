/**
 * @file ConfigParser.hpp
 * @date 26 Feb 2022
 * @author Yury Loshmanov
 */
#ifndef SERVER_CONFIGPARSER_HPP
#define SERVER_CONFIGPARSER_HPP

#include <string>
#include <boost/json.hpp>
#include <boost/property_tree/ptree.hpp>


class ConfigParser {
public:
    ConfigParser(const std::string &configFilePath = "config.json");

    std::string getPostgresqlURL();

protected:
    boost::property_tree::ptree pTree;
};


#endif //SERVER_CONFIGPARSER_HPP
