#pragma once

#include <string>

class Socket {
   public:
    Socket(int port, int backlog = 5);
    Socket(const Socket &other);
    ~Socket();

    int accept();
    void close();

    bool pending() const;

    Socket &operator=(const Socket &other);

   private:
    int _socket_fd = -1;

    void _socket();
    void _bind(int port);
    void _listen(int backlog);

    // Protected c function as a static private method
    static int _dup(int fd);
    static void _close(int fd);
};
