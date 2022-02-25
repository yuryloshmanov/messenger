/**
 * @file PostgresqlProxy
 * @date 19 Feb 2022
 * @author Yury Loshmanov
 */
#ifndef SERVER_POSTGRESQL_PROXY_HPP
#define SERVER_POSTGRESQL_PROXY_HPP

#include <string>
#include <pqxx/pqxx>

#include "DatabaseProxy.hpp"


class PostgresqlProxy : public DatabaseProxy {
    pqxx::connection connection;
    pqxx::work work;

public:
    PostgresqlProxy(const std::string &endPoint);

    bool addUser(const std::string &username);

    bool checkIfUserExists(const std::uint64_t &userId);

};


#endif //SERVER_POSTGRESQL_PROXY_HPP
