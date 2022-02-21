/**
 * @file DatabaseProxy.hpp
 * @date 2 Feb 2022
 * @author Yury Loshmanov
 */
#ifndef SERVER_DATABASE_PROXY_HPP
#define SERVER_DATABASE_PROXY_HPP


#include <string>
// TODO: Make thread-safe
#include <mutex>


class DatabaseProxy {
public:
    virtual void addUser(const std::string &username) = 0;

    virtual bool checkIfUserExists(std::uint64_t userId) = 0;

private:

};


#endif //SERVER_DATABASE_PROXY_HPP
