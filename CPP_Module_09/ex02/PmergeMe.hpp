#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>

class PmergeMe {
private:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

public:
    static void sortVector(std::vector<int>& arr);
    static void sortDeque(std::deque<int>& arr);
    static bool parseArguments(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq);
    static void printSequence(const std::vector<int>& vec);
    static double getTimeDiff(clock_t start, clock_t end);

private:
    static void mergeInsertSortVector(std::vector<int>& arr, int left, int right);
    static void mergeInsertSortDeque(std::deque<int>& arr, int left, int right);
    static void insertionSortVector(std::vector<int>& arr, int left, int right);
    static void insertionSortDeque(std::deque<int>& arr, int left, int right);
    static void mergeVector(std::vector<int>& arr, int left, int mid, int right);
    static void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
};

#endif
