/*
	Made by LioFires / Lio.

	Just another small program where I tested out function pointers.
*/

#include <iostream>

/**
* @class Basic_Math
* @description do basic math with 1 function
*/

class Basic_Math {

	public:
	
	/**
	* @name calculate_numbers
	* @description let you easily calculate basic math
	* @param val1
	* @param val2
	* @param opp - Function Pointer
	* @return String
	*/
	
	std::string calculate_numbers(double val1, double val2, double( * opp )(double, double))
	{
		std::string result { "The Result for the calculation is: " + std::to_string(( * opp)(val1, val2)) + "\n"};
		return result;
	}
	
	// need to be static functions
	static double add(double val1, double val2) { return val1 + val2; }
	static double sub(double val1, double val2) { return val1 - val2; }
	static double multi(double val1, double val2) { return val1 * val2; }
	static double devi(double val1, double val2) { return val1 / val2; }
};

int main()
{
	Basic_Math math;
	
	std::cout << math.calculate_numbers(7, 1, &Basic_Math::add);
	std::cout << math.calculate_numbers(5, 4, &Basic_Math::sub);
	std::cout << math.calculate_numbers(10, 40, &Basic_Math::multi);
	std::cout << math.calculate_numbers(19, 3, &Basic_Math::devi);
}