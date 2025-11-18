#pragma once

#include <vector>
#include <exception>

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
	int shortestSpan() const;
	int longestSpan() const;
};

