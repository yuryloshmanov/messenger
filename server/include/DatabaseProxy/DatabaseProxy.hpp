/**
 * @file DatabaseProxy.hpp
 * @date 2 Feb 2022
 * @author Yury Loshmanov
 */
#ifndef SERVER_DATABASE_PROXY_HPP
#define SERVER_DATABASE_PROXY_HPP


#include <string>


class DatabaseProxy {
public:
    virtual void addUser(const std::string &username) = 0;
    
private:

};


#endif //SERVER_DATABASE_PROXY_HPP
