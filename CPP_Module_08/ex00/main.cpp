#include "Easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>

int main()
{
    std::cout << "=== Testing easyfind function template ===" << std::endl;

    try
    {
        // Test 1: std::vector
        std::cout << "\n1. Testing with std::vector:" << std::endl;
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::cout << "Vector contents: ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        // Find existing value
        std::vector<int>::iterator found = easyfind(vec, 3);
        std::cout << "Found value 3 at position: " << (found - vec.begin()) << std::endl;
        std::cout << "Value at found position: " << *found << std::endl;

        // Test 2: std::list
        std::cout << "\n2. Testing with std::list:" << std::endl;
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);

        std::cout << "List contents: ";
        for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::list<int>::iterator foundInList = easyfind(lst, 20);
        std::cout << "Found value 20 in list: " << *foundInList << std::endl;

        // Test 3: std::deque
        std::cout << "\n3. Testing with std::deque:" << std::endl;
        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);
        deq.push_back(300);

        std::cout << "Deque contents: ";
        for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::deque<int>::iterator foundInDeque = easyfind(deq, 200);
        std::cout << "Found value 200 in deque: " << *foundInDeque << std::endl;

        // Test 4: std::set
        std::cout << "\n4. Testing with std::set:" << std::endl;
        std::set<int> s;
        s.insert(5);
        s.insert(15);
        s.insert(25);
        s.insert(35);

        std::cout << "Set contents: ";
        for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::set<int>::iterator foundInSet = easyfind(s, 15);
        std::cout << "Found value 15 in set: " << *foundInSet << std::endl;

        // Test 5: Testing with first and last elements
        std::cout << "\n5. Testing edge cases:" << std::endl;
        std::vector<int>::iterator first = easyfind(vec, 1);
        std::cout << "Found first element (1): " << *first << std::endl;

        std::vector<int>::iterator last = easyfind(vec, 5);
        std::cout << "Found last element (5): " << *last << std::endl;

        // Test 6: Exception handling - value not found
        std::cout << "\n6. Testing exception handling:" << std::endl;

        try
        {
            std::cout << "Trying to find value 999 in vector..." << std::endl;
            easyfind(vec, 999);
            std::cout << "ERROR: Should have thrown an exception!" << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }

        try
        {
            std::cout << "Trying to find value -1 in empty container..." << std::endl;
            std::vector<int> emptyVec;
            easyfind(emptyVec, -1);
            std::cout << "ERROR: Should have thrown an exception!" << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }

        // Test 7: Testing with duplicates
        std::cout << "\n7. Testing with duplicate values:" << std::endl;
        std::vector<int> dupVec;
        dupVec.push_back(7);
        dupVec.push_back(8);
        dupVec.push_back(7);  // duplicate
        dupVec.push_back(9);
        dupVec.push_back(7);  // another duplicate

        std::cout << "Vector with duplicates: ";
        for (std::vector<int>::iterator it = dupVec.begin(); it != dupVec.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::vector<int>::iterator firstSeven = easyfind(dupVec, 7);
        std::cout << "Found first occurrence of 7 at position: " << (firstSeven - dupVec.begin()) << std::endl;

        std::cout << "\n=== All tests completed successfully! ===" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
