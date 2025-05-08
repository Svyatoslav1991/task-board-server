#include "message.h"
#include <stdexcept>

std::vector<uint8_t> Message::serialize(const Message&) {
	throw std::runtime_error("Not implemented");
}

Message Message::parse(const std::vector<uint8_t>&) {
	throw std::runtime_error("Not implemented");
}
