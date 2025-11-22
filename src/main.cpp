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
    std::cout << "\n\n";


    std::cout << "--- 1. Parse Integers ---\n";
    const std::string ExampleText = "The year 2024 has 366 days";
    std::vector<int> ParsedText = Parse_Integers(ExampleText);

    std::cout << "Input: \"" << ExampleText << "\"\n";
    std::cout << "Integers: {";
    for (size_t i = 0; i < ParsedText.size(); ++i) {
        std::cout << ParsedText[i] << (i < ParsedText.size() - 1 ? ", " : "");
    }
    std::cout << "}\n\n";

    std::cout << "--- 2. Join Strings ---\n";
    std::vector<std::string> TestWords = { "Hello", "World", "!" };
    const std::string Delimiter = ", ";

    std::string JoinedString = Join_Strings(TestWords, Delimiter);

    std::cout << "Words: [Hello, World, !]\n";
    std::cout << "Delimiter: \"" << Delimiter << "\"\n";
    std::cout << "Result: \"" << JoinedString << "\"\n\n";

    std::vector<std::string> EmptyVector = {};
    std::cout << "Empty Result: \"" << Join_Strings(EmptyVector, ", ") << "\"\n\n";

    std::cout << "--- 3. Count Tokens ---\n";
    const std::string token_text_1 = "This is a sentence with seven tokens.";
    int token_count_1 = Count_Tokens(token_text_1);
    std::cout << "Input 1: \"" << token_text_1 << "\"\n";
    std::cout << "Token Count 1: " << token_count_1 << "\n";

    const std::string token_text_2 = "  Extra   spaces  between  words. ";
    int token_count_2 = Count_Tokens(token_text_2);
    std::cout << "Input 2: \"" << token_text_2 << "\"\n";
    std::cout << "Token Count 2: " << token_count_2 << "\n";
	return 0;
}