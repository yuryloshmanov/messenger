#include <iostream>

#include "include/terminal_client.hpp"


int main() {
    TerminalClient terminalClient;

    terminalClient.connectToServer("tcp://192.168.1.5:4040");
    terminalClient.run();

    return 0;
}
