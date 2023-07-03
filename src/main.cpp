#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fstream>

#include "hello-world.hpp"

void	server(void) {
// create socket
	const int	PORT = 8080;
	int			server_fd;
	int			connection;
	sockaddr_in address;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd < 0) {
		std::cerr << "Cannot create socket" << std::endl;
		return ;
	} else
		std::cout << "socket " << server_fd << " created" << std::endl;
	
// bind socket
	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.s_addr = INADDR_ANY;
	if (bind(server_fd, ((const sockaddr *)&address), sizeof(address)) < 0) {
		std::cerr << "Cannot bind socket" << std::endl;
		return ;
	} else
		std::cout << "socket " << server_fd << " bind success" << std::endl;
	
// wait for connection
	if (listen(server_fd, 3) < 0) {
		std::cerr << "Cannot hear socket" << std::endl;
		return ;
	} else
		std::cout << "socket " << server_fd << " loud and clear over" << std::endl;
	
	socklen_t len = sizeof(address);
	while (1) {
		connection = accept(server_fd, (struct sockaddr *)&address, &len);
		if (connection < 0) {
			std::cerr << "Cannot accept socket" << std::endl;
		} else
			std::cout << "socket " << server_fd << " accepted" << std::endl;

// receive info
		char buf[40000];
		long valread = read(connection, buf, 40000);
		std::cout << buf << std::endl;
		std::cout << "valread : " << valread << std::endl;

// send message
		std::fstream fs;
		fs.open("../include/index.html", std::fstream::in);
		std::string response = "this is Webserv over \n";
		
		std::string index = "HTTP/1.1 200 OK\nContent-Type: text/html; charset=utf-8\nContent-Length: 500\n\n";
		std::string temp;

		while(fs.good()) {
			fs >> temp;
			index.append(temp);
			index.append(" ");
		}
		std::cout << "index: \n" << index << std::endl;
		send(connection, index.c_str(), index.size(), 0);
		//send(connection, response.c_str(), response.size(), 0);
		std::cout << "hello message sent" << std::endl;

		close(connection);
	}
	close(server_fd);
}

int main()
{
	std::cout << hello_world() << std::endl;
	server();
	return 0;
}
