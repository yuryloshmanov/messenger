//
// Created by Yury Loshmanov on 02.02.2022.
//

#ifndef SERVER_SERVER_HPP
#define SERVER_SERVER_HPP

#include <string>
#include <zmqpp/zmqpp.hpp>


class Server {
public:

    // Get instance of Server class
    static Server &get();

    void run();

private:
    zmqpp::context context{};

    // Used for monitoring new connections
    zmqpp::socket pullSocket{context, zmqpp::socket_type::pull};

    // Private constructor & instance for singleton pattern
    Server() = default;

    // Configuration for server pull socket end point
    // Using current ip-address
    void configurePullSocketEndPoint();
};


#endif //SERVER_SERVER_HPP
