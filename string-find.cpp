/*

	Made by LioFires / Lio.
	
	Even older small program from around 2 years ago.

*/


#include <iostream>

bool contain(std::string word, std::string find) 
{
	return (word.find(find) != std::string::npos) ? 1 : 0;
}

const std::string test = "This is a test.";

int main()
{

	std::cout << contain(test, "."); // True
}