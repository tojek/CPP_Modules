/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:53:44 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/12/02 13:53:45 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

