/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:40:00 by omakran           #+#    #+#             */
/*   Updated: 2024/09/10 18:49:51 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <map> // for std::map
# include <fstream> // for std::ifstream
# include <sstream> // for std::istringstream

class BitcoinExchange
{
    // _exchangeRates is a map that stores the exchange rates for each date.
    std::map<std::string, std::string> _exchangeRates;
    
    public:
    BitcoinExchange();
    ~BitcoinExchange();

    void    loadExchangeRates(std::string const &filename);
    void    processInputFile(std::string const &filename);
};

#endif