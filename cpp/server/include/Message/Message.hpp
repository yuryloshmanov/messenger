/**
 * @file Message.hpp
 * @date 13 Feb 2022
 * @author Yury Loshmanov
 */
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
