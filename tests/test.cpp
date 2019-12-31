// Copyright 2018 Your Name <your_email>

#include <gtest/gtest.h>
#include <iostream>
#include <header.hpp>

TEST(Example, EmptyTest) {
	auto a = stack<int>();
	a.push(1);
	a.push(2);
	a.push(3);
	a.push(4);
	std::cout << a.head() << std::endl;
	a.pop();
	EXPECT_EQ(3, a.head());
}
