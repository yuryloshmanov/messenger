/**
 * @file MessageType.hpp
 * @date 13 Feb 2022
 * @author Yury Loshmanov
 */
#ifndef SERVER_MESSAGE_TYPE_HPP
#define SERVER_MESSAGE_TYPE_HPP


enum class MessageType {
    Heartbeat
};

MSGPACK_ADD_ENUM(MessageType)

#endif //SERVER_MESSAGE_TYPE_HPP
