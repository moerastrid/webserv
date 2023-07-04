#pragma once

#include <string>

#include "Connection.hpp"

class Socket {
   public:
    Socket(int port, int backlog = 5);
    Socket(const Socket &other) = delete;
    ~Socket();

    Connection accept();
    void close();
    bool pending() const;

    Socket &operator=(const Socket &other) = delete;

   private:
    int _socket_fd = -1;

    void _socket();
    void _bind(int port);
    void _listen(int backlog);
};
