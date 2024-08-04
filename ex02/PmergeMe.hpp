/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:54:49 by omakran           #+#    #+#             */
/*   Updated: 2024/08/04 01:56:19 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <ctime>
# include <algorithm>
# include <iomanip>
# include <sstream>

class PmergeMe {

    std::deque<long>    _deq;
    std::vector<long>   _vec;

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(PmergeMe const & src);
    PmergeMe & operator=(PmergeMe const & src);
    PmergeMe(int argc, char **argv);

    bool                isDigit(std::string str);
    std::deque<long>&   getDeq();
    std::vector<long>&  getVec();

    // ----------------- Functions of the Vector ------------------------ //
    void        merge(std::vector<long>& vec, int left, int mid, int right);
    void        mergeSortHelper(std::vector<long>& vec, int left, int right);
    std::string mergeSort(std::vector<long> vec);
    // ------------------------------------------------------------------ //
    
    // ------------------ Functions of the Deque ------------------------ //
    void        merge(std::deque<long>& deque, int left, int mid, int right);
    void        mergeSortHelper(std::deque<long>& deque, int left, int right);
    std::string mergeSort(std::deque<long> deque);
    // ------------------------------------------------------------------ //
};

#endif
