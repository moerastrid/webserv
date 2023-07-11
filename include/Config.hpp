#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <deque>
#include <iostream>
#include <string>
#include <string_view>
#include <map>
#include <array>

enum METHOD {
	GET,
	POST,
	DELETE
};

enum ERRORPAGE {
	ERROR400 = 400,
	ERROR404 = 401
};

struct LocationConfig {
	std::string			url = "";
	std::string			root_path = "";
	std::string			index_path = "index.html";
	std::array<bool, 3>	method = {true, true, true};
	bool				accept_files = false;
	bool				directory_listening = true;
	std::string			cgi = "php";
	std::string 		storage_path = "default_storage";
};

struct ServerConfig {
	std::deque<unsigned int>			port = 0;
	std::deque<std::string>				host = "default_server";
	std::deque<std::string>				server_names = {"default.org", "www.default.org"};
	double								client_max_body_size = 1000000; // nginx default = 1m
	std::map<ERRORPAGE, std::string>	error_path = {{ERROR400, "error400.html"}, {ERROR404, "error404.html"}};
	std::deque<LocationConfig>			locations;
};

struct Config {
	std::string					config_file = "config/webserv.conf";
	std::deque<ServerConfig>	servers = {ServerConfig()};
};

class ConfigException : public std::exception {
	public :
		virtual const char * what() const throw();
};

std::ostream	&operator<<(std::ostream &o, Config const &i);
std::ostream	&operator<<(std::ostream &o, ServerConfig const &i);
std::ostream	&operator<<(std::ostream &o, LocationConfig const &i);

#endif