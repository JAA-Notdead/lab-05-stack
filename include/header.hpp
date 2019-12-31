// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <utility>
#include <stdexcept>
#include <type_traits>

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
	}
	void push(T&& value) {
		auto temp = current;
		current = new StackElement();
		current->prev = temp;
		current->value = std::move(value);
	}
	void push(const T& value) {
		if constexpr (std::is_copy_assignable<T>::value) {
			auto temp = current;
			current = new StackElement();
			current->prev = temp;
			current->value = value;
		}
		else {
			throw std::logic_error("Cannot assign non-copy-assignable types! Use stack::push_emplace");
		}
	}
	template<typename ...Args>
	void push_emplace(Args&&... value) {
		if constexpr (!std::is_copy_assignable<T>::value) {
			auto temp = current;
			current = new StackElement(temp, value...);
		}
		else {
			throw std::logic_error("Use stack::push");
		}
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
		template<typename ... Args>
		StackElement(StackElement* a, Args&& ...values) :prev(a), value(values...) {

		}
		StackElement() {

		}
	} *current;
};

#endif // INCLUDE_HEADER_HPP_
