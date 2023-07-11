#include "parse_headers.hpp"
#include <gtest/gtest.h>

// static std::unordered_map<std::string, std::string> build_result() {
// 	std::unordered_map<std::string, std::string> map;
// 	return map;
// }

TEST(parse_header, empty_input) {
	std::string input;
	std::unordered_map<std::string, std::string> header_map = parse_headers(input);
	std::unordered_map<std::string, std::string> result = {};

	EXPECT_EQ(header_map, result);
}

TEST(parse_header, newline_input) {
	std::string input = "\n";
	std::unordered_map<std::string, std::string> header_map = parse_headers(input);
	std::unordered_map<std::string, std::string> result = {{"METHOD_PAGE_PROTOCOL", ""}};

	EXPECT_EQ(header_map, result);
}

TEST(parse_header, multiple_newline_input) {
	std::string input = "\n\n\n";
	std::unordered_map<std::string, std::string> header_map = parse_headers(input);
	std::unordered_map<std::string, std::string> result = {{"METHOD_PAGE_PROTOCOL", ""}};

	EXPECT_EQ(header_map, result);
}

TEST(parse_header, head_input) {
	std::string input = "GET / HTTP/1.1\n";
	std::unordered_map<std::string, std::string> header_map = parse_headers(input);
	std::unordered_map<std::string, std::string> result = {{"METHOD_PAGE_PROTOCOL", "GET / HTTP/1.1"}};

	EXPECT_EQ(header_map, result);
}

TEST(parse_header, basic_input) {
	std::string input = R"(GET / HTTP/1.1
Host: localhost
Connection: keep-alive)";
	std::unordered_map<std::string, std::string> header_map = parse_headers(input);
	std::unordered_map<std::string, std::string> result = {{"METHOD_PAGE_PROTOCOL", "GET / HTTP/1.1"}, {"Host", " localhost"}, {"Connection", " keep-alive"}};

	EXPECT_EQ(header_map, result);
}

TEST(parse_header, duplicate_input) {
	std::string input = R"(GET / HTTP/1.1
Host: localhost
Host: another_host)";
	std::unordered_map<std::string, std::string> header_map = parse_headers(input);
	std::unordered_map<std::string, std::string> result = {{"METHOD_PAGE_PROTOCOL", "GET / HTTP/1.1"}, {"Host", " localhost, another_host"}};

	EXPECT_EQ(header_map, result);
}

// 	const std::string input = R"(GET / HTTP/1.1
// Host: localhost
// Connection: keep-alive
// sec-ch-ua: \"Not.A/Brand\";v=\"8\", \"Chromium\";v=\"114\", \"Google Chrome\";v=\"114\"
// sec-ch-ua-mobile: ?0
// sec-ch-ua-platform: \"macOS\"
// Upgrade-Insecure-Requests: 1
// User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36
// Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7
// Sec-Fetch-Site: none
// Sec-Fetch-Mode: navigate
// Sec-Fetch-User: ?1
// Sec-Fetch-Dest: document
// Sec-Fetch-Dest: another_doc
// Accept-Encoding: gzip, deflate, br
// Accept-Language: en-US,en;q=0.9
// No-space-after-colon:Y
// :
// :no head
// Empty:)";