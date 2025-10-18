#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other) : maxSize(other.maxSize), numbers(other.numbers) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		maxSize = other.maxSize;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (numbers.size() >= maxSize) {
		throw std::out_of_range("Span is full");
	}
	numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (numbers.size() < 2) {
		throw std::logic_error("Cannot find span with less than 2 numbers");
	}

	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() const {
	if (numbers.size() < 2) {
		throw std::logic_error("Cannot find span with less than 2 numbers");
	}

	int min = *std::min_element(numbers.begin(), numbers.end());
	int max = *std::max_element(numbers.begin(), numbers.end());
	return max - min;
}
