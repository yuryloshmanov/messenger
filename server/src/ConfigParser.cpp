/**
 * @file ConfigParser.cpp
 * @date 27 Feb 2022
 * @author Yury Loshmanov
 */

#include "../include/ConfigParser.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/foreach.hpp>
#include <boost/property_tree/json_parser.hpp>


ConfigParser::ConfigParser(const std::string &configFilePath) {
    std::fstream fs(configFilePath, std::ios::in);

    std::stringstream ss;
    std::copy(
            std::istream_iterator<char>(fs),
            std::istream_iterator<char>(),
            std::ostream_iterator<char>(ss)
    );

    boost::property_tree::read_json(ss, pTree);
}

