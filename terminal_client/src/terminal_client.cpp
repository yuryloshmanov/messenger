//
// Created by Yury Loshmanov on 06.02.2022.
//

#include "../include/terminal_client.hpp"


void TerminalClient::connectToServer(const std::string &serverAddress) {
    pushSocket.connect(serverAddress);
}


void TerminalClient::run() {
    zmqpp::message message;
    std::string str = "Hello, ZeroMQ!";

    message << str;
    pushSocket.send(message);
}
