/**
 * @file DatabaseProxy.hpp
 * @date 2 Feb 2022
 * @author Yury Loshmanov
 */
#ifndef SERVER_DATABASE_PROXY_HPP
#define SERVER_DATABASE_PROXY_HPP


#include <pqxx/pqxx>
#include <string>
// TODO: Make thread-safe
#include <mutex>


class DatabaseProxy {
public:
    /**
     * Add user to database
     * @param username must be unique
     * @return true if user successfully added, false if user with this username already exists
     */
    virtual bool addUser(const std::string &username) = 0;

    /**
     * Checks if user exists in database
     * @param userId
     * @return true if user exists, false if not
     */
    virtual bool checkIfUserExists(const std::uint64_t &userId) = 0;

private:

};


#endif //SERVER_DATABASE_PROXY_HPP
