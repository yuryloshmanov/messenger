//
// Created by Yury Loshmanov on 02.02.2022.
//

#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "../include/Server.hpp"


Server &Server::get() {
    return instance;
}


void Server::configurePullSocketEndPoint(const std::string &endPoint) {
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
}
