#include "Span.hpp"


int main() {
	std::cout << "Test from subject " << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}


	std::cout << "\nTest with exception (full span) " << std::endl;
	try {
		Span sp = Span(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4); // Should throw
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}


	std::cout << "\nTest with not enough numbers " << std::endl;
	try {
		Span sp = Span(10);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl; // Should throw
	} catch (std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}


	std::cout << "\nTest with range of iterators (10,000 numbers) " << std::endl;
	try {
		std::vector<int> numbers;
		std::srand(std::time(0));
		for (int i = 0; i < 10000; ++i) {
			numbers.push_back(std::rand() % 100000);
			// numbers.push_back(std::rand());
		}
		Span sp = Span(10000);
		sp.addNumber(numbers.begin(), numbers.end());
		std::cout << "Added 10,000 numbers using iterator range" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}


	std::cout << "\nTest with 20,000 numbers " << std::endl;
	try {
		Span sp = Span(20000);
		
		std::vector<int> numbers;
		for (int i = 0; i < 20000; ++i) {
			numbers.push_back(std::rand());
		}
		sp.addNumber(numbers.begin(), numbers.end());
		std::cout << "Added 20,000 random numbers" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	
	std::cout << "\nTest with negative numbers " << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(5);
		sp.addNumber(10);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}