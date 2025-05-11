#include <gtest/gtest.h>
#include "message.h"

TEST(MessageTest, SerializeAndParseRoundTrip) {
	Message orig;
	orig.body = "Hello, TDD!";

	// ������������ �� ������ �������
	std::vector<uint8_t> bytes;
	EXPECT_NO_THROW(bytes = Message::serialize(orig));

	// ������ �� ������ �������
	Message parsed;
	EXPECT_NO_THROW(parsed = Message::parse(bytes));

	// ����� �������� ���� ������ ���������
	EXPECT_EQ(parsed.body, orig.body);
}