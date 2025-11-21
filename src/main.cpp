#pragma once

#include "Lab_07.h"

int main()
{
	const std::string Filename = "../src/Test_Data.txt";

	std::vector<double> Data = Read_Numbers(Filename);
	std::cout << Count_Positive(Data) << std::endl;
	std::cout << Count_Negative(Data) << std::endl;
	std::cout << Count_Zero(Data) << "\n\n" << std::endl;

    int X = 45, Y = 12, Z = 33;
    std::cout << "Original: " << X << ", " << Y << ", " << Z << std::endl;
    Sort_Three(X, Y, Z);
    std::cout << "Sorted: " << X << ", " << Y << ", " << Z << std::endl;
	Increment_All(X, Y, Z, 2);
    std::cout << "Incremented: " << X << ", " << Y << ", " << Z << std::endl;
	Make_Equal(X, Y, Z);
    std::cout << "Made Equal: " << X << ", " << Y << ", " << Z << std::endl;

	return 0;
}