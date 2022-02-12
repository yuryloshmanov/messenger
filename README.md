# Messenger

## Design
### Server
### Monitoring new connecitons
Using pull socket type for monitoring new connections.
Pull socket doesn't need to respond to client, therefore, it's suitable for this type of usage.
```cpp
zmqpp::socket pullSocket{context, zmqpp::socket_type::pull;
```

Message to be sent is the address of client's socket.
It includes `tcp://` + ip + `:` + port.

### Dealing with clients
Using request socket for clients and reply socket for server.


