// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <utility>
template<typename T>
class stack{
public:
	// Non-copyable
	stack(const stack&) = delete;
	// Moveable
	stack(stack&&) = default;
	stack() {
		current = new StackElement();
		current->prev = nullptr;
		current->value = T();
	}
	void push(T&& value) {
		auto temp = current;
		current = new StackElement();
		current->prev = temp;
		current->value = std::move(value);
	}
	void push(const T& value) {
		auto temp = current;
		current = new StackElement();
		current->prev = temp;
		current->value = value;
	}
	void pop() {
		if (current->prev != nullptr) {
			auto temp = current;
			current = current->prev;
			delete temp;
		}
	}
	const T& head() const {
		return current->value;
	}
private:
	struct StackElement {
		StackElement* prev;
		T value;
	} *current;
};

#endif // INCLUDE_HEADER_HPP_
