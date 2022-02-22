/**
 * @file PostgresqlProxy
 * @date 19 Feb 2022
 * @author Yury Loshmanov
 */
#ifndef SERVER_POSTGRESQL_PROXY_HPP
#define SERVER_POSTGRESQL_PROXY_HPP

#include "DatabaseProxy.hpp"


class PostgresqlProxy : public DatabaseProxy {
public:
    PostgresqlProxy(const std::string &endPoint);
};


#endif //SERVER_POSTGRESQL_PROXY_HPP
