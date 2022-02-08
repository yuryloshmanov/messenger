//
// Created by Yury Loshmanov on 06.02.2022.
//

#include "../include/console_client.hpp"


void ConsoleClient::connectToServer(const std::string &serverAddress) {
    pushSocket.connect(serverAddress);
}


void ConsoleClient::run() {
    zmqpp::message message;
    std::string str = "Hello, ZeroMQ!";

    message << str;
    pushSocket.send(message);
}
