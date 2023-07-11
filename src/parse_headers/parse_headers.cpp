#include "parse_headers.hpp"

#include <sstream>
#include <string>

static std::vector<std::string> ws_split_on_colon(std::string str) {
	std::vector<std::string> lines;

	size_t colon = str.find(":");
	if (colon == str.npos)
		return lines;

	std::string head(str.c_str(), colon);
	std::string body(str, colon + 1, str.size() - colon - 1);

	lines.push_back(head);
	lines.push_back(body);

	return lines;
}

static void merge_or_insert(std::unordered_map<std::string, std::string> &map, const std::string& key, const std::string& value) {
	auto it = map.find(key);
	if(it != map.end()) {
		it->second += "," + value;
	} else {
		map.emplace(key, value);	
	}
}

std::unordered_map<std::string, std::string> parse_headers(const std::string message) {
	std::unordered_map<std::string, std::string> header_map;
	if (message.empty())
		return header_map;

	std::vector<std::string> lines;
	std::string line;
	std::istringstream ss(message);
	if(ss.bad() || ss.fail())
		return header_map;

	while (getline(ss, line)) {
		lines.push_back(line);
	}

	std::string first = lines.front(); //fell off
	lines.erase(lines.begin());

	header_map.emplace("METHOD_PAGE_PROTOCOL", first);

	for (std::string const & line : lines) {
		if(line.empty())
			continue;
		std::vector<std::string> header = ws_split_on_colon(line);
		std::string head = header.front();
		std::string body = header.back();
		// if(!head.empty() && !body.empty()) //Either, both or neither??
		merge_or_insert(header_map, head, body);
	}
	return header_map;
}
