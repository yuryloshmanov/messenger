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

    pullSocket.bind(fmt::format("tcp://{}:4040", ipBuffer));

    Logger::consoleLog(fmt::format("Pull socket has been binded at tcp://{}:4040", ipBuffer));
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

        std::string endPoint;
        message >> endPoint;

        threads.emplace_back(&Server::clientMonitor, &Server::get(), endPoint);
    }
}


void Server::clientMonitor(const std::string &endPoint) {
    zmqpp::socket socket(context, zmqpp::socket_type::reply);
    socket.connect(endPoint);

    while (true) {
        zmqpp::message request, reply;
        socket.receive(request);
        std::string str;
        request >> str;
        std::cout << fmt::format("Request: {}", str) << std::endl;

        reply << std::string("server reply sample");
        socket.send(reply);
    }
}
