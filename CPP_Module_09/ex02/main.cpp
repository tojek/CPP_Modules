/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:54:00 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/12/02 13:54:01 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    if (!PmergeMe::parseArguments(argc, argv, vec, deq)) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    if (vec.empty()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    PmergeMe::printSequence(vec);
    std::cout << std::endl;

    clock_t startVec = clock();
    PmergeMe::sortVector(vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    PmergeMe::sortDeque(deq);
    clock_t endDeq = clock();

    std::cout << "After:  ";
    PmergeMe::printSequence(vec);
    std::cout << std::endl;

    double timeVec = PmergeMe::getTimeDiff(startVec, endVec);
    double timeDeq = PmergeMe::getTimeDiff(startDeq, endDeq);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;

    return 0;
}
