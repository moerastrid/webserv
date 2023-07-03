#include <sys/socket.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main() {
	int fd = socket(PF_LOCAL, SOCK_STREAM, 0);
	if (fd == -1) {
		cerr << "cannot open socket" << endl;
		return 1;
	}

	struct sockaddr_in address;
	struct sockaddr *sendr = (struct sockaddr *)&address;

	address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

	connect(fd, sendr, sizeof(address));

	string message = "This is a message";
	send(fd, message.c_str(), message.size(), 0);
	cout << "message sent" << endl;
}