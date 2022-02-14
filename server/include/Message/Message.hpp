//
// Created by Yury Loshmanov on 13.02.2022.
//

#ifndef SERVER_MESSAGE_HPP
#define SERVER_MESSAGE_HPP

#include <msgpack.hpp>

#include "MessageType.hpp"


class Message {
public:
    MessageType messageType;

    MSGPACK_DEFINE (messageType)
};


#endif //SERVER_MESSAGE_HPP
