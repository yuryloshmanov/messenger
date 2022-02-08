//
// Created by Yury Loshmanov on 02.02.2022.
//

#include <netdb.h>
#include <unistd.h>
#include <thread>
#include <arpa/inet.h>
#include <fmt/format.h>

#include "../include/Server.hpp"


Server &Server::get() {
    static Server instance;
    return instance;
}


void Server::configurePullSocketEndPoint() {
    char buffer[256];
    char *ipBuffer;
    struct hostent *host_entry;

    if (gethostname(buffer, sizeof buffer) == -1) {
        throw std::runtime_error("Can't get hostname");
    }

    host_entry = gethostbyname(buffer);
    if (!host_entry) {
        throw std::runtime_error("Can't get host");
    }

    ipBuffer = inet_ntoa(*((struct in_addr *) host_entry->h_addr_list[0]));
    if (!ipBuffer) {
        throw std::runtime_error("Can't get ip");
    }

    std::string result(ipBuffer);
    pullSocket.bind("tcp://" + std::string(ipBuffer) + ":4040");

    logger.consoleLog(fmt::format("Pull socket has been binded at tcp://{}:4040", ipBuffer));
}


void Server::run() {
    configurePullSocketEndPoint();
    std::thread newConnectionsMonitorThread(&Server::newConnectionsMonitor, &Server::get());
    newConnectionsMonitorThread.join();
}


[[noreturn]] void Server::newConnectionsMonitor() {
    while (true) {
        zmqpp::message message;
        pullSocket.receive(message); // blocks

        std::string str;
        message >> str;

        std::cout << str << std::endl;
    }
}
