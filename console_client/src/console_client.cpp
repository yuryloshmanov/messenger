//
// Created by Yury Loshmanov on 06.02.2022.
//

#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fmt/format.h>

#include "../include/console_client.hpp"


std::string getAddress() {
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

    return fmt::format("tcp://{}:5050", ipBuffer);
}


void ConsoleClient::connectToServer(const std::string &serverAddress) {
    pushSocket.connect(serverAddress);
}


void ConsoleClient::run() {
    const auto address = getAddress();
    zmqpp::socket socket(context, zmqpp::socket_type::request);
    socket.bind(address);

    zmqpp::message message;
    message << address;
    pushSocket.send(message);

    while (true) {
        zmqpp::message request, reply;
        request << "client request sample";
        socket.send(request);

        socket.receive(reply);
        std::string str;
        reply >> str;
        std::cout << fmt::format("Reply: {}", str) << std::endl;
    }
}
