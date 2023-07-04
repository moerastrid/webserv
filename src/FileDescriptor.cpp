#include "FileDescriptor.hpp"

#include <unistd.h>

#include <stdexcept>

FileDescriptor::FileDescriptor() : _fd(-1) {}

FileDescriptor::FileDescriptor(int fd) : _fd(fd) {
    if (_fd < 0) {
        throw std::runtime_error("FileDescriptor: Invalid file descriptor");
    }
}

FileDescriptor::~FileDescriptor() {
    try {
        close();
    } catch (const FileDescriptorCloseException& e) {
        // Ignore
    }
}

void FileDescriptor::close() {
    if (_fd < 0) {
        return;
    }
    if (::close(_fd) < 0) {
        throw FileDescriptorCloseException();
    }
    _fd = -1;
}

int FileDescriptor::getFD() const {
    return _fd;
}

void FileDescriptor::setFD(int fd) {
    if (_fd >= 0) {
        throw std::runtime_error("FileDescriptor: File descriptor already set");
    }
    if (fd < 0) {
        throw std::runtime_error("FileDescriptor: Invalid file descriptor");
    }
    _fd = fd;
}
