/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:39:53 by omakran           #+#    #+#             */
/*   Updated: 2024/07/28 22:24:54 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

//      load the exchange rates from the file and store them in the _exchangeRates map.
void    BitcoinExchange::loadExchangeRates(std::string const &filename) {
    std::ifstream file(filename.c_str()); // c_str() is used to convert a C++ string to a C-style string
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        exit (1);
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line); // stringstream to pares the line
        std::string date, rate;

        if (std::getline(ss, date, ',') && std::getline(ss, rate, ',')) {
            _exchangeRates.insert(std::pair<std::string, std::string>(date, rate));
        }
    }
    file.close();
}

void    BitcoinExchange::processInputFile(std::string const &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        exit (1);
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr, '|')) {
            try {
                double value = std::strtod(valueStr.c_str(), NULL);
                if (value > 1000 || std::isnan(value)) {
                    std::cerr << "Error: too large a number." << std::endl;
                    continue;                       // skip to the next line if invalid
                }
                if (value < 0) {
                    std::cerr << "Error: not a positive number." << std::endl;
                    continue;
                }
                // Find the closest date in exchangeRates that is not greater than the input date
                std::map<std::string, std::string>::iterator it = _exchangeRates.lower_bound(date);
                if (it != _exchangeRates.begin() && (it == _exchangeRates.end() || it->first != date)) {
                    --it;  // if exact date not found, move to the previous date
                }

                if (it == _exchangeRates.end() || date < it->first) {
                    std::cerr << "Error: bad input => " << date << std::endl;
                } else {
                    double rate = std::strtod(it->second.c_str(), NULL);
                    std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
                }
            } catch (...) {
                std::cerr << "Error: invalid value format => " << valueStr << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}

// Explication
/*

{
    "2011-01-01": 0.3,
    "2011-01-02": 0.35,
    "2011-01-04": 0.4
}

If the input date is "2011-01-03", the iterator it would not find an exact match (it->first != "2011-01-03"),
and it might point to "2011-01-04" if 'upper_bound' or similar method was used.

The code then checks if it is at the beginning or end of the map or if it->first is not the date we're looking for.
If true, it decrements it to point to "2011-01-02", which is the closest date before "2011-01-03".

*/