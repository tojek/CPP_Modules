/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:53:42 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/12/02 13:53:43 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
	{
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // skip column names

    while (std::getline(file, line))
	{
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            std::string valueStr = line.substr(commaPos + 1);
            double value = std::atof(valueStr.c_str());
            _exchangeRates[date] = value;
        }
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
	{
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line))
	{
        size_t pipePos = line.find(" | ");
        if (pipePos == std::string::npos)
		{
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 3);

        if (!isValidDate(date))
		{
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value = std::atof(valueStr.c_str());
        if (valueStr.empty() || (!isValidValue(value) && valueStr != "0"))
		{
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (value > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double rate = getExchangeRate(date);
        if (rate >= 0)
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
    file.close();
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _exchangeRates.find(date);

    if (it != _exchangeRates.end())
        return it->second;

    it = _exchangeRates.lower_bound(date);

    if (it == _exchangeRates.begin())
        return -1; // search before the first date

    --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
		return false;

    if (date[4] != '-' || date[7] != '-')
		return false;

    for (int i = 0; i < 10; ++i)
	{
        if (i == 4 || i == 7)
			continue;
        if (date[i] < '0' || date[i] > '9')
			return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
		return false;
    if (day < 1 || day > 31)
		return false;
    if (year < 1000)
		return false;

    return true;
}

bool BitcoinExchange::isValidValue(double value) const
{
    return (value >= 0 && value <= 1000);
}
