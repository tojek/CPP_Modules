#!/bin/bash

# Compile the program
c++ -Wall -Wextra -Werror main.cpp -o replace

# Create test files
echo "Hello World! Hello Universe!" > test1.txt
echo "aaa aaa aaa" > test2.txt
echo "No matches here" > test3.txt
echo -n "Testing without newline" > test4.txt
echo "Multiple\nLine\nTest" > test5.txt

# Run tests
echo "Test 1: Basic replacement"
./replace test1.txt "Hello" "Hi"
cat test1.txt.replace
echo

echo "Test 2: Replace with longer string"
./replace test2.txt "a" "abc"
cat test2.txt.replace
echo

echo "Test 3: Replace with shorter string"
./replace test2.txt "aaa" "x"
cat test2.txt.replace
echo

echo "Test 4: No matches"
./replace test3.txt "xyz" "abc"
cat test3.txt.replace
echo

echo "Test 5: File without newline"
./replace test4.txt "Testing" "Checking"
cat test4.txt.replace
echo

# Error cases
echo "Test 6: Non-existent file"
./replace nonexistent.txt "a" "b"

echo "Test 7: Empty string replacement"
./replace test1.txt "" "something"

# Cleanup
rm -f test*.txt test*.txt.replace replace
