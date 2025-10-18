#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Span {
private:
	unsigned int maxSize;
	std::vector<int> numbers;

public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;

	template <typename InputIterator>
	void addNumber(InputIterator first, InputIterator last) {
		while (first != last) {
			if (numbers.size() >= maxSize) {
				throw std::out_of_range("Span is full");
			}
			numbers.push_back(*first);
			++first;
		}
	}
};



