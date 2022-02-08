//
// Created by Yury Loshmanov on 06.02.2022.
//

#ifndef CONSOLE_CLIENT_CONSOLE_CLIENT_HPP
#define CONSOLE_CLIENT_CONSOLE_CLIENT_HPP

#include <string>
#include <zmqpp/zmqpp.hpp>


class ConsoleClient {
public:
    // Default constructor
    consoleClient() = default;

    // Connect to server via specified address
    void connectToServer(const std::string &serverAddress);

    // Main function to communicate with server
    void run();

private:
    zmqpp::context context{};

    // Socket to connect to server
    zmqpp::socket pushSocket{context, zmqpp::socket_type::push};
};


#endif //CONSOLE_CLIENT_CONSOLE_CLIENT_HPP
