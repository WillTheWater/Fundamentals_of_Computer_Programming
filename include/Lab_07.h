#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

// TASK 1: Function Overloading - Absolute Value
// Write three overloaded functions called 'absolute' that return absolute values.
// Requirements:
// - int absolute(const int value) - returns absolute value of integer
// - double absolute(const double value) - returns absolute value of double
// - void absolute(std::vector<int> & vec) - converts all elements to absolute values in-place
// - Test all three versions with different inputs
// - For vector version, print before and after
// - Test with: absolute(-42), absolute(-3.14), absolute(vector{-5, 10, -15, 20})

int Absolute(const int Value)
{
	return Value < 0 ? -Value : Value;
}

double Absolute(const double Value)
{
	return Value < 0.0 ? -Value : Value;
}

void Absolute(std::vector<int>& Vector)
{
	for (int i = 0; i < Vector.size(); i++)
	{
		Vector[i] = Absolute(Vector[i]);
	}
}

// TASK 2: File Writing - Student Records
// Write a function that writes student records to a file.
// Requirements:
// - Function signature: bool write_students(const std::string & filename, 
//                                           const std::vector<std::string> & names,
//                                           const std::vector<int> & scores)
// - Each line format: "Name: [name], Score: [score]"
// - Return true if successful, false if vectors have different sizes or file fails
// - Test with at least 5 students
// - Print success/failure message and verify file contents

bool Write_Students(const std::string& FileName, const std::vector<std::string>& Names, const std::vector<int>& Scores)
{
	if (Names.size() != Scores.size())
	{
		std::cerr << "Error: Name count does not match score count." << std::endl;
		return false;
	}

	std::ofstream OutFile{ FileName };
	if (!OutFile)
	{
		std::cerr << "Failed to load: " << FileName << std::endl;
		return false;
	}

	for (auto i = 0; i < Names.size(); i++)
	{
		OutFile << "Name: " << Names[i] << ", Score: " << Scores[i] << std::endl;
	}
	std::cout << "Successfully created " << FileName << std::endl;
	return true;
}

// TASK 3: File Reading - Number Statistics
// Write functions to read numbers from a file and analyze them.
// Requirements:
// - std::vector<double> read_numbers(const std::string & filename)
//   - reads all numbers from file (one per line or space-separated)
//   - returns vector of numbers
// - int count_positive(const std::vector<double> & numbers)
//   - counts how many numbers are positive
// - int count_negative(const std::vector<double> & numbers)
//   - counts how many numbers are negative
// - First create a file with numbers, then read and analyze it
// - Print: total count, positive count, negative count, zero count

std::vector<double> Read_Numbers(const std::string& Filename) 
{
	std::vector<double> Numbers;
	std::ifstream InFile(Filename);

	if (!InFile) 
	{
		std::cerr << "Error: Could not open file " << Filename << std::endl;
		return Numbers;
	}

	double Number;
	
	while (InFile >> Number) 
	{
		Numbers.push_back(Number);
	}

	return Numbers;
}

int Count_Positive(const std::vector<double>& Numbers)
{
	int Count = 0;
	for (double Number : Numbers)
	{
		if (Number > 0) { Count++; }
	}
	return Count;
}

int Count_Negative(const std::vector<double>& Numbers)
{
	int Count = 0;
	for (double Number : Numbers)
	{
		if (Number < 0) { Count++; }
	}
	return Count;
}

// TASK 4: Reference Parameters - Sort Three Values
// Write functions that work with references to sort and manipulate values.
// Requirements:
// - void sort_three(int & a, int & b, int & c) - sorts three integers in ascending order
//   (a will be smallest, c will be largest)
// - void increment_all(int & a, int & b, int & c, const int value) - adds value to all three
// - void make_equal(int & a, int & b, int & c) - sets all three to their average
// - Test with three variables initialized to: 45, 12, 33
// - Show values after each function call

// TASK 5: String Stream Processing
// Write functions that use std::stringstream for string manipulation.
// Requirements:
// - std::vector<int> parse_integers(const std::string & text)
//   - extracts all integers from a string (use stringstream)
//   - example: "The year 2024 has 366 days" -> {2024, 366}
// - std::string join_strings(const std::vector<std::string> & words, const std::string & delimiter)
//   - joins vector of strings with delimiter between them
//   - example: {"Hello", "World", "!"} with ", " -> "Hello, World, !"
// - int count_tokens(const std::string & text)
//   - counts space-separated tokens using stringstream
// - Test with various strings and print results

// TASK 6: Recursive Array Operations
// Write recursive functions to work with arrays.
// Requirements:
// - int array_sum_recursive(const int array[], const int length, const int index = 0)
//   - recursively calculates sum of array elements
//   - base case: index >= length returns 0
// - int find_max_recursive(const int array[], const int length, const int index = 0)
//   - recursively finds maximum value in array
//   - base case: index == length-1 returns array[index]
//   - hint: return max of current element and max of rest
// - Test with array: {34, 67, 12, 89, 45, 23, 78}
// - Compare with iterative results to verify correctness

// TASK 7: Multi-File Data Processing
// Create a program that processes multiple data files.
// Requirements:
// - Create struct: struct DataSummary { 
//     std::string filename; 
//     int line_count;
//     int word_count;
//     int char_count;
//   };
// - Write function: DataSummary analyze_file(const std::string & filename)
//   - counts lines, words (space-separated), and characters in file
//   - returns DataSummary with all statistics
// - Write function: void print_summary(const DataSummary & summary)
//   - prints all statistics in readable format
// - Write function: void compare_files(const std::string & file1, const std::string & file2)
//   - analyzes both files and prints which has more lines/words/chars
// - Create 2-3 test files with different content and analyze them