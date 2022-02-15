/**
 * @file Server.hpp
 * @date 2 Feb 2022
 * @author Yury Loshmanov
 */

#ifndef SERVER_SERVER_HPP
#define SERVER_SERVER_HPP

#include <string>
#include <vector>
#include <thread>
#include <zmqpp/zmqpp.hpp>

#include "../include/Message/Message.hpp"
#include "../include/Logger.hpp"


class Server {
public:

    /**
     * Get instance of Server class
     * @return reference to server
     */
    static Server &get();

    // Main function for server
    // Starts server
    void run();

private:
    zmqpp::context context{};

    // Used for monitoring new connections
    zmqpp::socket pullSocket{context, zmqpp::socket_type::pull};

    // To consoleLog everything important
    Logger logger{};

    // Storage for threads monitoring clients
    std::vector<std::thread> threads;

    // Private constructor & instance for singleton pattern
    Server() = default;

    // Configuration for server pull socket end point
    // Using current ip-address
    void configurePullSocketEndPoint();

    // Waits for new clients to be connected
    // Monitors pull socket
    // Should run in separate thread or by using concurrency
    [[noreturn]] void newConnectionsMonitor();

    // When new connection satisfied,
    // this function in separate thread
    // listens client
    [[noreturn]] void clientMonitor(const std::string &clientEndPoint);
};


#endif //SERVER_SERVER_HPP
