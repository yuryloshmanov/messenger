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

    // Main function for server
    // Starts server
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

    // Waits for new clients to be connected
    // Monitors pull socket
    // Should run in separate thread or by using concurrency
    void newConnectionsMonitor();
};


#endif //SERVER_SERVER_HPP
