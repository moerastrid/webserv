#include <sys/socket.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>

using namespace std;

int main() {
	close(3);
	int fd = socket(PF_LOCAL, SOCK_STREAM, 0);
	if (fd == -1) {
		cerr << "cannot open socket" << endl;
		return 1;
	}

	cout << fd << endl;
	struct sockaddr_in address;
	struct sockaddr *sendr = (struct sockaddr *)&address;
	int addrlen = sizeof(address);
	socklen_t* socklen = (socklen_t*)&addrlen;

	int opt = 1;
	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}

	address.sin_family = PF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);

	// if (bind(fd, ((const sockaddr *)&address), sizeof(address)) < 0) {
	// 	std::cerr << "Cannot bind socket" << std::endl;
	// 	return 1;
	// } else
	// 	std::cout << "socket " << fd << " bind success" << std::endl;

	int val = bind(fd, sendr, addrlen);
	if (val < 0) {
		perror("bind failed");
		return 1;
	}
	cout << "bound" << endl;
	if (listen(fd, 3) < 0) {
		perror("listen failed");
		return 1;
	}
	cout << "listened" << endl;
	int new_socket = accept(fd, sendr, socklen);
	if (new_socket < 0) {
		perror("accept failed");
		return 1;
	}
	cout << "accepted" << endl;

	char *buffer = new char[1024];
	recv(new_socket, buffer, 1024, MSG_DONTWAIT);
	printf("%s\n", buffer);
	string message = "This is another message";
	
	send(new_socket, message.c_str(), message.size(), 0);
	printf("Hello message sent\n");
  
	// closing the connected socket
	close(new_socket);
	// closing the listening socket
	shutdown(fd, SHUT_RDWR);
	return 0;
}