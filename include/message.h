#pragma once
#include <string>
#include <vector>
#include <cstdint>

struct Message {
	std::string body;

	static std::vector<uint8_t> serialize(const Message& msg);
	static Message parse(const std::vector<uint8_t>& data);
};
