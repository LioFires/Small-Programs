/*
Made by LioFires / Lio

	This is just a small program I made around 1 year ago since I wanted to test out concepts.
*/

#include <iostream>

template<typename Type>
concept Arithmeticable_Type = requires(Type)
{
	requires sizeof(Type) >= 4;
};

template<Arithmeticable_Type Num,
				Arithmeticable_Type PositiveNumber =
				typename std::remove_reference<Num>::type>
				
PositiveNumber add(Num & return_value, const Num & value_1 = 0, const Num & value_2 = 0)
		requires std::integral<Num> || std::floating_point<Num> // concepts C++20
{
	if (value_1 <= 0 || value_2 <= 0) throw std::invalid_argument("Only positive numeric values.");
	
	return_value = { value_1 + value_2 };
	return return_value;
}

int main()
{
	int value {}, value_1 {56}, value_2 {23};
	add(value, value_1, value_2);
	
	std::cout << "The sum is: " << value << std::endl;
}