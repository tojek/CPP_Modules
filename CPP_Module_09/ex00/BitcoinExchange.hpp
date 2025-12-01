#pragma once

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange {
private:
    std::map<std::string, double> _exchangeRates;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename);
    double getExchangeRate(const std::string& date) const;
    bool isValidDate(const std::string& date) const;
    bool isValidValue(double value) const;
};

