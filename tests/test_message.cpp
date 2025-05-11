#include <gtest/gtest.h>
#include "message.h"

TEST(MessageTest, SerializeAndParseRoundTrip) {
	Message orig;
	orig.body = "Hello, TDD!";

	// Сериализация не должна бросать
	std::vector<uint8_t> bytes;
	EXPECT_NO_THROW(bytes = Message::serialize(orig));

	// Разбор не должен бросать
	Message parsed;
	EXPECT_NO_THROW(parsed = Message::parse(bytes));

	// После парсинга тело должно совпадать
	EXPECT_EQ(parsed.body, orig.body);
}