// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <iostream>
#include <header.hpp>

class NonCopyAssignable {

public:
	int a;
	float b;
	NonCopyAssignable& operator= (const NonCopyAssignable&) = delete;
	NonCopyAssignable(int c, float d) {
		a = c;
		b = d;
	}
	NonCopyAssignable() = default;
};

TEST(Example, EmptyTest) {
	auto a = stack<int>();
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	std::cout << a.head() << std::endl;
	a.pop();
	EXPECT_EQ(3, a.head());
	auto b = stack<NonCopyAssignable>();
	b.push_emplace(1, 2.0);
	b.push_emplace(3, 4.0);
	b.pop();
	EXPECT_EQ(2.0, b.head().b);
}
