/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:39:45 by omakran           #+#    #+#             */
/*   Updated: 2024/09/10 19:24:19 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char __unused **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    } else {
        BitcoinExchange exchange;
        exchange.loadExchangeRates("./data.csv"); // load exchange rates from the specified file.
        exchange.processInputFile(argv[1]);
        
    }
    return 0;
}