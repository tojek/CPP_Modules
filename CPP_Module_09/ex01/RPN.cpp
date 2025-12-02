/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:53:55 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/12/02 13:53:56 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

int RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;

    // Clear the stack before processing
    while (!_stack.empty())
	{
        _stack.pop();
    }

    while (iss >> token)
	{
        if (isValidNumber(token))
		{
            int num = std::atoi(token.c_str());
            _stack.push(num);
        }
        else if (isOperator(token))
		{
            if (_stack.size() < 2)
                throw std::runtime_error("Error"); //not enough operands

            int b = _stack.top();
					_stack.pop();
            int a = _stack.top();
					_stack.pop();

            int result = performOperation(a, b, token);
            _stack.push(result);
        }
        else
            throw std::runtime_error("Error");
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}

bool RPN::isOperator(const std::string& token) const
{
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::performOperation(int a, int b, const std::string& op) const
{
    if (op == "+")
		return a + b;
    if (op == "-")
		return a - b;
    if (op == "*")
		return a * b;
    if (op == "/")
	{
        if (b == 0)
            throw std::runtime_error("Error");
        return a / b;
    }
    throw std::runtime_error("Error");
}

bool RPN::isValidNumber(const std::string& token) const
{
    if (token.empty())
		return false;

    if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
        return true;

    return false;
}
