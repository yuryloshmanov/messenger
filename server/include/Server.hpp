//
// Created by Yury Loshmanov on 02.02.2022.
//

#ifndef SERVER_SERVER_HPP
#define SERVER_SERVER_HPP

#include <string>
#include <zmqpp/zmqpp.hpp>


class Server {
public:
    static Server &get();

    static void configurePullSocketEndPoint(const std::string &endPoint);

private:
    zmqpp::context context{};
    zmqpp::socket pullSocket{context, zmqpp::socket_type::pull};

    Server() = default;

    static Server instance;
};


#endif //SERVER_SERVER_HPP
