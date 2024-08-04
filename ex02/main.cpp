/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:54:43 by omakran           #+#    #+#             */
/*   Updated: 2024/08/04 21:48:35 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    try {
        if (argc < 2)
            throw std::runtime_error("Error");
        PmergeMe    p(argc, argv);
        std::cout << "Before: ";
        std::vector<long>   vec = p.getVec();
        if (vec.size() <= 5){
            for (size_t i = 0; i < vec.size() && i < 5; i++) {
                std::cout << vec[i] << " ";
            }
        }
        else {
            for (size_t i = 0; i < vec.size() && i < 4; i++) {
                std::cout << vec[i] << " ";
            }
            std::cout << "[...]"; // print only the first 6 elements
        }
        std::cout << "\n";
        std::deque<long>    deq = p.getDeq();
        std::string         str;
        clock_t             start = clock(); // start time
        str = p.mergeSort(vec);
        clock_t             end_v = clock(); // end time
        clock_t             start_d = clock();
        str = p.mergeSort(deq);
        clock_t             end_d = clock();
        double duration_v = double(end_v - start) * 1000000.0 / CLOCKS_PER_SEC;
        double duration_d = double(end_d - start_d) * 1000000.0 / CLOCKS_PER_SEC;
        std::cout << "After: " << str << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << std::fixed << std::setprecision(5) << duration_v << " us" << std::endl;
        std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << std::setprecision(5) << duration_d << " us" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}