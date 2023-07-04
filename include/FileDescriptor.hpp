#pragma once

#include <stdexcept>

class FileDescriptor {
   public:
    void close();

    class FileDescriptorCloseException : public std::runtime_error {
       public:
        FileDescriptorCloseException() : std::runtime_error("Failed to close file descriptor") {}
    };

   protected:
    FileDescriptor();
    FileDescriptor(int fd);
    FileDescriptor(const FileDescriptor& other) = delete;
    ~FileDescriptor();

    int getFD() const;
    void setFD(int fd);

    FileDescriptor& operator=(const FileDescriptor& other) = delete;

   private:
    int _fd = -1;
};
