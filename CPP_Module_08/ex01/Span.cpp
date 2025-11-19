#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
	{
		throw std::runtime_error("Span is already full");
	}
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size() - 1; ++i)
	{
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (span < minSpan)
		{
			minSpan = span;
		}
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");

	int minNumber = *std::min_element(_numbers.begin(), _numbers.end());
	int maxNumber = *std::max_element(_numbers.begin(), _numbers.end());

	return maxNumber - minNumber;
}

// Template implementation moved to header file

unsigned int Span::size() const
{
	return _numbers.size();
}

unsigned int Span::maxSize() const
{
	return _maxSize;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	size_t distanceSize = std::distance(begin, end);
	if (_numbers.size() + distanceSize > _maxSize)
	{
			throw std::runtime_error("Adding these numbers would exceed Span capacity");
	}
	_numbers.insert(_numbers.end(), begin, end);
}