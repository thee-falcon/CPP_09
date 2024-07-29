/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:40:00 by omakran           #+#    #+#             */
/*   Updated: 2024/07/29 01:21:14 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map> // for std::map
# include <fstream> // for std::ifstream
# include <sstream> // for std::istringstream

class BitcoinExchange
{
    std::map<std::string, std::string> _exchangeRates;
    
    public:
    BitcoinExchange();
    ~BitcoinExchange();

    void    loadExchangeRates(std::string const &filename);
    void    processInputFile(std::string const &filename);
};

#endif