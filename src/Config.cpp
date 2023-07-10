#include "Config.hpp"

const char * ConfigException::what() const throw() {
	return ("Config Exception : exception");
}

std::ostream &operator<<(std::ostream &o, LocationConfig const &loccon) {
	o << "LOCAITON: (url: " << loccon.url << ", root: " << loccon.root_path << " index: " << loccon.index_path << ", storage : " << loccon.storage_path;
	o << ", method: GET-" << loccon.method[GET] << " POST-" << loccon.method[POST] << " DELETE-" << loccon.method[DELETE];
	o << ", accept_files: " << loccon.accept_files << ", directory_listening: " << loccon.directory_listening << ", cgi: " << loccon.cgi << ")";
	return (o);
}

std::ostream &operator<<(std::ostream &o, ServerConfig const &sercon) {
	o << "SERVER: port: " << sercon.port << ", host: " << sercon.host << ", server names:";
	for (const std::string & str : sercon.server_names)
		o << " " << str;
	o << ", client max body size: " << sercon.client_max_body_size << ", errorpages: ";
	for (const std::pair<ERRORPAGE, std::string> mypair : sercon.error_path) {
		std::cout << '[' << mypair.first << "]=" << mypair.second << " ";
	}
	return (o);
}

std::ostream &operator<<(std::ostream &o, Config const &con) {
	std::deque<ServerConfig>::const_iterator	temp;
	for (const ServerConfig &server : con.servers) {
		o << "CONFIG: " << server;
	}
	return (o);
}
