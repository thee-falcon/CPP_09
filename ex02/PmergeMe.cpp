/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakran <omakran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:54:46 by omakran           #+#    #+#             */
/*   Updated: 2024/09/10 19:04:25 by omakran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(PmergeMe const & src) {
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & src) {
    if (this != &src) {
        this->_deq = src._deq;
        this->_vec = src._vec;
    }
    return *this;
}

std::deque<long> & PmergeMe::getDeq() {
    return this->_deq;
}

std::vector<long> & PmergeMe::getVec() {
    return this->_vec;
}

bool PmergeMe::isDigit(std::string str) {
    if (str[0] == '+' && str.size() > 1) {
        str = str.substr(1); // remove the '+' sign
    }
    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false; // if any character is not a digit
        }
    }
    return true;
}

PmergeMe::PmergeMe(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (!isDigit(argv[i]))
            throw std::runtime_error("Error");
        double num = strtod(argv[i], NULL);
        if (num > 2147483647)
            throw std::runtime_error("Error");
        this->_deq.push_back(num);
        this->_vec.push_back(num); 
    }
}

//      ---------------------------- Vector -----------------------------------
//          function to perform merge sort on a vector of long integers
std::string PmergeMe::mergeSort(std::vector<long> vec) {
    mergeSortHelper(vec, 0, vec.size() - 1); // -1 because the last index is size - 1

    // convert sorted vector to string
    std::ostringstream oss;
    if (vec.size() <= 5) {
        for (size_t i = 0; i < vec.size(); ++i) {
            oss << vec[i];
            if (i < vec.size() - 1)
                oss << " ";
        }
    } else {
        for (size_t i = 0; i < 4; ++i) {
            oss << vec[i];
            if (i < 3)
                oss << " ";
        }
        oss << " [...]"; // print only the first 6 elements
    }
    // return the sorted vector as a string
    return oss.str();  
}

//      helper function to implement merge sort
void    PmergeMe::mergeSortHelper(std::vector<long>& vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // sort first and second halves
        mergeSortHelper(vec, left, mid);
        mergeSortHelper(vec, mid + 1, right);

        // merge the sorted halves
        merge(vec, left, mid, right);
    }    
}

void    PmergeMe::merge(std::vector<long>& vec, int left, int mid, int right) {
    // n1 is the size of the first half
    int n1 = mid - left + 1; // + 1 because the index starts from 0
    int n2 = right - mid; // the size of the second half

    // create temporary arrays
    std::vector<long> L(n1);
    std::vector<long> R(n2);

    // copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = vec[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = vec[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;
    // sorting and merging
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            ++i;
        } else {
            vec[k] = R[j];
            ++j;
        }
        ++k;
    }
    // copy the remaining elements, if there are any to vec[]
    while (i < n1) {
        vec[k] = L[i];
        ++i;
        ++k;
    }
    // copy the remaining elements, if there are any to vec[]
    while (j < n2) {
        vec[k] = R[j];
        ++j;
        ++k;
    }   
}

//      ---------------------------- Deque -----------------------------------
//          function to perform merge sort on a deque of long integers
std::string PmergeMe::mergeSort(std::deque<long> deq) {
    mergeSortHelper(deq, 0, deq.size() - 1);

    // convert sorted deque to string
    std::ostringstream oss;
    if (deq.size() <= 5) {
        for (size_t i = 0; i < deq.size(); ++i) {
            oss << deq[i];
            if (i < deq.size() - 1)
                oss << " ";
        }
    } else {
        for (size_t i = 0; i < 4; ++i) {
            oss << deq[i];
            if (i < 3)
                oss << " ";
        }
        oss << " [...]"; // print only the first 6 elements
    }
    return oss.str();
}

//      helper function to implement merge sort
void    PmergeMe::mergeSortHelper(std::deque<long>& deq, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // sort first and second halves
        mergeSortHelper(deq, left, mid);
        mergeSortHelper(deq, mid + 1, right);

        // merge the sorted halves
        merge(deq, left, mid, right);
    }    
}

void    PmergeMe::merge(std::deque<long>& deq, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temporary arrays
    std::deque<long> L(n1);
    std::deque<long> R(n2);

    // copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = deq[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = deq[mid + 1 + i];

    // merge the temporary arrays back into deq[left..right]
    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            deq[k] = L[i];
            ++i;
        } else {
            deq[k] = R[j];
            ++j;
        }
        ++k;
    }
    // copy the remaining elements of L[], if there are any
    while (i < n1) {
        deq[k] = L[i];
        ++i;
        ++k;
    }
    // copy the remaining elements of R[], if there are any
    while (j < n2) {
        deq[k] = R[j];
        ++j;
        ++k;
    }   
}

