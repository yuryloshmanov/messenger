//
// Created by Yury Loshmanov on 02.02.2022.
//

#ifndef SERVER_SERVER_HPP
#define SERVER_SERVER_HPP


class Server {
public:
    static Server get();

private:
    Server() = default;
    static Server instance;
};


#endif //SERVER_SERVER_HPP
