/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:23:52 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/11/20 11:23:53 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void testBasicFunctionality()
{
    std::cout << "=== Testing Basic Functionality ===" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Span contents: 6, 3, 17, 9, 11" << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;  // Should be 2
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;    // Should be 14
}

void testExceptionHandling()
{
    std::cout << "\n=== Testing Exception Handling ===" << std::endl;

    try
    {
        Span smallSpan(2);
        smallSpan.addNumber(1);
        smallSpan.addNumber(2);
        std::cout << "Added 2 numbers to span of size 2" << std::endl;

        std::cout << "Trying to add third number..." << std::endl;
        smallSpan.addNumber(3); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    try
    {
        Span emptySpan(10);
        std::cout << "Trying to find shortest span in empty span..." << std::endl;
        emptySpan.shortestSpan(); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    try
    {
        Span singleSpan(10);
        singleSpan.addNumber(42);
        std::cout << "Trying to find longest span with only one number..." << std::endl;
        singleSpan.longestSpan(); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }
}

void testAddNumbers()
{
    std::cout << "\n=== Testing addNumbers() Function ===" << std::endl;

    // Test 1: Basic functionality
    std::cout << "1. Testing basic addNumbers functionality:" << std::endl;
    std::vector<int> basicVec;
    basicVec.push_back(10);
    basicVec.push_back(20);
    basicVec.push_back(30);
    basicVec.push_back(40);
    basicVec.push_back(50);

    Span basicSpan(10);
    basicSpan.addNumbers(basicVec.begin(), basicVec.end());
    std::cout << "Added " << basicSpan.size() << " numbers: 10, 20, 30, 40, 50" << std::endl;
    std::cout << "Shortest span: " << basicSpan.shortestSpan() << std::endl; // Should be 10
    std::cout << "Longest span: " << basicSpan.longestSpan() << std::endl;   // Should be 40

    // Test 2: Adding to existing span
    std::cout << "\n2. Testing addNumbers to span with existing numbers:" << std::endl;
    Span mixedSpan(10);
    mixedSpan.addNumber(5);
    mixedSpan.addNumber(15);

    std::vector<int> additionalVec;
    additionalVec.push_back(25);
    additionalVec.push_back(35);

    mixedSpan.addNumbers(additionalVec.begin(), additionalVec.end());
    std::cout << "Started with: 5, 15" << std::endl;
    std::cout << "Added from vector: 25, 35" << std::endl;
    std::cout << "Total numbers: " << mixedSpan.size() << std::endl;
    std::cout << "Shortest span: " << mixedSpan.shortestSpan() << std::endl; // Should be 10
    std::cout << "Longest span: " << mixedSpan.longestSpan() << std::endl;   // Should be 30

    // Test 3: Partial vector range
    std::cout << "\n3. Testing partial vector range:" << std::endl;
    std::vector<int> largeVec;
    for (int i = 1; i <= 10; ++i)
    {
        largeVec.push_back(i * 5); // 5, 10, 15, 20, 25, 30, 35, 40, 45, 50
    }

    Span partialSpan(5);
    // Add only middle elements (15, 20, 25)
    partialSpan.addNumbers(largeVec.begin() + 2, largeVec.begin() + 5);
    std::cout << "Added elements from index 2-4: 15, 20, 25" << std::endl;
    std::cout << "Numbers added: " << partialSpan.size() << std::endl;
    std::cout << "Shortest span: " << partialSpan.shortestSpan() << std::endl; // Should be 5
    std::cout << "Longest span: " << partialSpan.longestSpan() << std::endl;   // Should be 10

    // Test 4: Empty vector
    std::cout << "\n4. Testing empty vector:" << std::endl;
    std::vector<int> emptyVec;
    Span emptyTestSpan(5);
    emptyTestSpan.addNumbers(emptyVec.begin(), emptyVec.end());
    std::cout << "Added from empty vector, size: " << emptyTestSpan.size() << std::endl;

    // Test 5: Single element vector
    std::cout << "\n5. Testing single element vector:" << std::endl;
    std::vector<int> singleVec;
    singleVec.push_back(42);
    Span singleSpan(5);
    singleSpan.addNumbers(singleVec.begin(), singleVec.end());
    std::cout << "Added single element: 42, size: " << singleSpan.size() << std::endl;

    // Test 6: Capacity exception
    std::cout << "\n6. Testing capacity exception:" << std::endl;
    try
    {
        std::vector<int> tooManyVec;
        for (int i = 1; i <= 15; ++i)
        {
            tooManyVec.push_back(i);
        }

        Span smallSpan(10);
        std::cout << "Trying to add 15 numbers to span of capacity 10..." << std::endl;
        smallSpan.addNumbers(tooManyVec.begin(), tooManyVec.end());
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // Test 7: Mixed with individual adds, then exceed capacity
    std::cout << "\n7. Testing mixed operations with capacity limit:" << std::endl;
    try
    {
        Span limitSpan(8);
        limitSpan.addNumber(1);
        limitSpan.addNumber(2);
        limitSpan.addNumber(3);
        std::cout << "Added 3 individual numbers" << std::endl;

        std::vector<int> fiveMore;
        for (int i = 4; i <= 8; ++i)
        {
            fiveMore.push_back(i);
        }
        limitSpan.addNumbers(fiveMore.begin(), fiveMore.end());
        std::cout << "Added 5 more via addNumbers, total: " << limitSpan.size() << std::endl;

        // This should work (exactly at capacity)
        std::cout << "Span is exactly full" << std::endl;

        // Now try to add one more
        std::vector<int> oneMore;
        oneMore.push_back(9);
        limitSpan.addNumbers(oneMore.begin(), oneMore.end());
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception when exceeding capacity: " << e.what() << std::endl;
    }
}

void testLargeSpan()
{
    std::cout << "\n=== Testing Large Span (10,000+ numbers) ===" << std::endl;

    const unsigned int LARGE_SIZE = 20000;
    std::cout << "Creating span of size " << LARGE_SIZE << std::endl;

    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    Span largeSpan(LARGE_SIZE);

    // Generate random numbers
    std::vector<int> randomNumbers;
    for (unsigned int i = 0; i < LARGE_SIZE; ++i)
    {
        randomNumbers.push_back(std::rand() % 100000); // Random numbers 0-99999
    }

    std::cout << "Adding " << LARGE_SIZE << " random numbers using iterator range..." << std::endl;
    largeSpan.addNumbers(randomNumbers.begin(), randomNumbers.end());

    std::cout << "Span size: " << largeSpan.size() << "/" << largeSpan.maxSize() << std::endl;

    // Calculate spans
    std::cout << "Calculating shortest span..." << std::endl;
    int shortest = largeSpan.shortestSpan();

    std::cout << "Calculating longest span..." << std::endl;
    int longest = largeSpan.longestSpan();

    std::cout << "Results for " << LARGE_SIZE << " random numbers:" << std::endl;
    std::cout << "Shortest span: " << shortest << std::endl;
    std::cout << "Longest span: " << longest << std::endl;
}

void testEdgeCases()
{
    std::cout << "\n=== Testing Edge Cases ===" << std::endl;

    // Test with negative numbers
    std::cout << "Testing with negative numbers:" << std::endl;
    Span negativeSpan(5);
    negativeSpan.addNumber(-10);
    negativeSpan.addNumber(-5);
    negativeSpan.addNumber(0);
    negativeSpan.addNumber(5);
    negativeSpan.addNumber(10);

    std::cout << "Numbers: -10, -5, 0, 5, 10" << std::endl;
    std::cout << "Shortest span: " << negativeSpan.shortestSpan() << std::endl; // Should be 5
    std::cout << "Longest span: " << negativeSpan.longestSpan() << std::endl;   // Should be 20

    // Test with duplicate numbers
    std::cout << "\nTesting with duplicate numbers:" << std::endl;
    Span duplicateSpan(6);
    duplicateSpan.addNumber(1);
    duplicateSpan.addNumber(1);
    duplicateSpan.addNumber(5);
    duplicateSpan.addNumber(5);
    duplicateSpan.addNumber(10);
    duplicateSpan.addNumber(10);

    std::cout << "Numbers: 1, 1, 5, 5, 10, 10" << std::endl;
    std::cout << "Shortest span: " << duplicateSpan.shortestSpan() << std::endl; // Should be 0
    std::cout << "Longest span: " << duplicateSpan.longestSpan() << std::endl;   // Should be 9
}

int main()
{
    std::cout << "=== Span Class Comprehensive Testing ===" << std::endl;

    try
    {
        testBasicFunctionality();
        testExceptionHandling();
        testAddNumbers();
        testLargeSpan();
        testEdgeCases();

        std::cout << "\n=== All tests completed successfully! ===" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "\nUnexpected exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
