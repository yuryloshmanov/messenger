//
// Created by Yury Loshmanov on 06.02.2022.
//

#ifndef TERMINAL_CLIENT_TERMINAL_CLIENT_HPP
#define TERMINAL_CLIENT_TERMINAL_CLIENT_HPP

#include <string>
#include <zmqpp/zmqpp.hpp>


class TerminalClient {
public:
    // Default constructor
    TerminalClient() = default;

    // Connect to server via specified address
    void connectToServer(const std::string &serverAdress);

    // Main function to communicate with server
    void run();

private:
    zmqpp::context context{};

    // Socket to connect to server
    zmqpp::socket pushSocket{context, zmqpp::socket_type::push};
};


#endif //TERMINAL_CLIENT_TERMINAL_CLIENT_HPP
