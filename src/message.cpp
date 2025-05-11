#include "message.h"
#include <stdexcept>
#include <algorithm>

// Помощник для big-endian записи
static void writeUint32BE(uint32_t v, uint8_t* dest) {
	dest[0] = (v >> 24) & 0xFF;
	dest[1] = (v >> 16) & 0xFF;
	dest[2] = (v >> 8) & 0xFF;
	dest[3] = v & 0xFF;
}

std::vector<uint8_t> Message::serialize(const Message& msg) {
	uint32_t len = static_cast<uint32_t>(msg.body.size());
	std::vector<uint8_t> out(4 + len);
	writeUint32BE(len, out.data());
	std::copy(msg.body.begin(), msg.body.end(), out.begin() + 4);
	return out;
}

Message Message::parse(const std::vector<uint8_t>& data) {
	if (data.size() < 4)
		throw std::runtime_error("Data too short");
	uint32_t len = (uint32_t(data[0]) << 24)
		| (uint32_t(data[1]) << 16)
		| (uint32_t(data[2]) << 8)
		| uint32_t(data[3]);
	if (data.size() - 4 != len)
		throw std::runtime_error("Length mismatch");
	Message msg;
	msg.body.assign(reinterpret_cast<const char*>(data.data() + 4), len);
	return msg;
}
