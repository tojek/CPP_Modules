/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:53:57 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/12/02 13:53:58 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN {
private:
    std::stack<int> _stack;

public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    int evaluate(const std::string& expression);
    bool isOperator(const std::string& token) const;
    int performOperation(int a, int b, const std::string& op) const;
    bool isValidNumber(const std::string& token) const;
};

