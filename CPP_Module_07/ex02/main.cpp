/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:25:39 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/11/05 19:32:41 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <string>

void testDefaultInitialization()
{
    std::cout << "\n=== Testing Default Initialization ===" << std::endl;

    Array<int> intArray(5);
    std::cout << "int array[5] default values: ";
    for (size_t i = 0; i < intArray.size(); ++i)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    Array<std::string> strArray(3);
    std::cout << "string array[3] default values: ";
    for (size_t i = 0; i < strArray.size(); ++i)
    {
        std::cout << "\"" << strArray[i] << "\" ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "=== Array Class Template Tests ===" << std::endl;

    try
    {
        // Test 1: Default constructor
        std::cout << "\n1. Testing default constructor:" << std::endl;
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        // Test 2: Parameterized constructor
        std::cout << "\n2. Testing parameterized constructor:" << std::endl;
        Array<int> intArray(5);
        std::cout << "Array size: " << intArray.size() << std::endl;
        for (size_t i = 0; i < intArray.size(); ++i)
        {
            intArray[i] = static_cast<int>(i * 10);
        }

        std::cout << "Array contents: ";
        for (size_t i = 0; i < intArray.size(); ++i)
        {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Test 3: Copy constructor
        std::cout << "\n3. Testing copy constructor:" << std::endl;
        Array<int> copiedArray(intArray);
        std::cout << "Copied array size: " << copiedArray.size() << std::endl;
        std::cout << "Copied array contents: ";
        for (size_t i = 0; i < copiedArray.size(); ++i)
        {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        // test deep copy
        intArray[0] = 999;
        std::cout << "After modifying original[0] to 999:" << std::endl;
        std::cout << "Original array[0]: " << intArray[0] << std::endl;
        std::cout << "Copied array[0]: " << copiedArray[0] << std::endl;

        // Test 4: Assignment operator
        std::cout << "\n4. Testing assignment operator:" << std::endl;
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
        std::cout << "Assigned array contents: ";
        for (size_t i = 0; i < assignedArray.size(); ++i)
        {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test 5: Different types
        std::cout << "\n5. Testing with different types:" << std::endl;
        Array<std::string> stringArray(4);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "C++";
        stringArray[3] = "Templates";

        std::cout << "String array: ";
        for (size_t i = 0; i < stringArray.size(); ++i)
        {
            std::cout << "\"" << stringArray[i] << "\" ";
        }
        std::cout << std::endl;

        // Test 6: Const array access
        std::cout << "\n6. Testing const array access:" << std::endl;
        const Array<int> constArray = copiedArray;
        std::cout << "Const array[2]: " << constArray[2] << std::endl;

        testDefaultInitialization();

        // Test 7: Exception handling
        std::cout << "\n7. Testing exception handling:" << std::endl;

        try
        {
            std::cout << "Trying to access index 10 in array of size 5..." << std::endl;
            std::cout << intArray[10] << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        try
        {
            std::cout << "Trying to access index 0 in empty array..." << std::endl;
            std::cout << emptyArray[0] << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // Test 8: Large array
        std::cout << "\n8. Testing large array:" << std::endl;
        Array<double> largeArray(1000);
        std::cout << "Created array of " << largeArray.size() << " doubles" << std::endl;
        largeArray[999] = 3.14159;
        std::cout << "Last element: " << largeArray[999] << std::endl;

        std::cout << "\n=== All tests completed successfully! ===" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
