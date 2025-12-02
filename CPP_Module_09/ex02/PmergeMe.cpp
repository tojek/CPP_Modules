#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseArguments(int argc, char** argv, std::vector<int>& vec, std::deque<int>& deq)
{
    for (int i = 1; i < argc; i++)
	{
        std::string arg = argv[i];

        for (size_t j = 0; j < arg.length(); j++)
		{
            if (!std::isdigit(arg[j]))
                return false;
        }

        std::stringstream ss(arg);
        int num;
        ss >> num;

        if (ss.fail() || num < 0)
            return false;

        vec.push_back(num);
        deq.push_back(num);
    }

    return true;
}

void PmergeMe::printSequence(const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size() && i < 5; i++)
	{
        std::cout << vec[i] << " ";
    }
    if (vec.size() > 5)
	{
        std::cout << "[...]";
    }
}

double PmergeMe::getTimeDiff(clock_t start, clock_t end)
{
	double seconds = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	double microseconds = seconds * 1000000.0;
	return microseconds;
}

// Vector implementation

// sort from 2nd element, check if current key is smaller;
// if smaller, shift larger value to right
/*
Array: [5, 2, 4, 6, 1, 3]  (sorting from index 0 to 5)

i=1, key=2: [2, 5, 4, 6, 1, 3]  // 2 inserted before 5
i=2, key=4: [2, 4, 5, 6, 1, 3]  // 4 inserted between 2 and 5
i=3, key=6: [2, 4, 5, 6, 1, 3]  // 6 already in place
i=4, key=1: [1, 2, 4, 5, 6, 3]  // 1 moved to front
i=5, key=3: [1, 2, 3, 4, 5, 6]  // 3 inserted in correct spot
*/
void PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
	{
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right)
{
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    size_t i = 0, j = 0;
    int k = left;
/*
leftArr  = [2, 5, 8]
rightArr = [1, 3, 9]

Merge: 1, 2, 3, 5, 8, 9
*/
    while (i < leftArr.size() && j < rightArr.size())
	{
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }
//cleanup and speed up
    while (i < leftArr.size())
	{
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size())
	{
        arr[k++] = rightArr[j++];
    }
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& arr, int left, int right)
{
    if (right - left < 10)
	{
        insertionSortVector(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    mergeInsertSortVector(arr, left, mid);
    mergeInsertSortVector(arr, mid + 1, right);
    mergeVector(arr, left, mid, right);
}

void PmergeMe::sortVector(std::vector<int>& arr)
{
    if (arr.size() <= 1)
		return;
    mergeInsertSortVector(arr, 0, arr.size() - 1);
}

// Deque implementation
void PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
	{
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
		{
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
    std::deque<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::deque<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    size_t i = 0, j = 0;
    int k = left;

    while (i < leftArr.size() && j < rightArr.size())
	{
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < leftArr.size())
	{
        arr[k++] = leftArr[i++];
    }

    while (j < rightArr.size())
	{
        arr[k++] = rightArr[j++];
    }
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& arr, int left, int right)
{
    if (right - left < 10)
	{
        insertionSortDeque(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    mergeInsertSortDeque(arr, left, mid);
    mergeInsertSortDeque(arr, mid + 1, right);
    mergeDeque(arr, left, mid, right);
}

void PmergeMe::sortDeque(std::deque<int>& arr)
{
    if (arr.size() <= 1)
		return;
    mergeInsertSortDeque(arr, 0, arr.size() - 1);
}
