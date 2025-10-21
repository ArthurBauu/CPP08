#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	std::cout << "=== Test with MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << "Top: " << mstack.top() << std::endl;
		
		mstack.pop();
		
		std::cout << "Size: " << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		std::cout << "Elements:" << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		
		// Test conversion to std::stack
		std::stack<int> s(mstack);
		std::cout << "Converted to std::stack, size: " << s.size() << std::endl;
	}

	std::cout << "\n=== Same test with std::list (for comparison) ===" << std::endl;
	{
		std::list<int> mstack;
		
		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << "Top: " << mstack.back() << std::endl;
		
		mstack.pop_back();
		
		std::cout << "Size: " << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		
		std::cout << "Elements:" << std::endl;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		
		std::cout << "List size: " << mstack.size() << std::endl;
	}

	std::cout << "\n=== Additional tests ===" << std::endl;
	{
		MutantStack<std::string> strStack;
		strStack.push("Hello");
		strStack.push("World");
		strStack.push("42");
		
		std::cout << "String stack elements:" << std::endl;
		for (MutantStack<std::string>::iterator it = strStack.begin(); 
		     it != strStack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test copy constructor ===" << std::endl;
	{
		MutantStack<int> original;
		original.push(1);
		original.push(2);
		original.push(3);
		
		MutantStack<int> copy(original);
		
		std::cout << "Original: ";
		for (MutantStack<int>::iterator it = original.begin(); 
		     it != original.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		
		std::cout << "Copy: ";
		for (MutantStack<int>::iterator it = copy.begin(); 
		     it != copy.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n=== Test assignment operator ===" << std::endl;
	{
		MutantStack<int> stack1;
		stack1.push(10);
		stack1.push(20);
		
		MutantStack<int> stack2;
		stack2.push(99);
		
		stack2 = stack1;
		
		std::cout << "Stack2 after assignment: ";
		for (MutantStack<int>::iterator it = stack2.begin(); 
		     it != stack2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
