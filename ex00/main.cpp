/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:39:45 by omakran           #+#    #+#             */
/*   Updated: 2024/07/28 20:59:55 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char __unused **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    } else {
        BitcoinExchange exchange;
        exchange.loadExchangeRates("/Users/omakran/Desktop/CPP_09/ex00/data.csv"); // load exchange rates from the specified file.
        exchange.processInputFile(argv[1]);
        
    }
    return 0;
}