#pragma once

#include <stack>
#include <deque>
#include <iterator>

// deque = double-ended queue (c'est le conteneur par défaut pour std::stack)

template <typename T>
class MutantStack : public std::stack<T> {
public:
	
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;
};

#include "MutantStack.tpp"

