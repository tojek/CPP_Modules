#pragma once

#include <vector>
#include <exception>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
	unsigned int        _maxSize;
	std::vector<int>    _numbers;
public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	int shortestSpan() const;
	int longestSpan() const;

	unsigned int size() const;
	unsigned int maxSize() const;
};

