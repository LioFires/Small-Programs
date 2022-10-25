/*

By LioFires / Lio.

	Simple program I made to this type of math by myself. It was never done.
*/

#include <iostream>
#include <random> // C++11
#include <string>
#include <thread> // sleep()
#include <sstream>

bool if_quit(bool & keep_going)
{
	char ans;
	std::cout << "Do you want to keep going? [Y/N] ";
	std::cin >> ans;
	
	return (ans == 'N') ? keep_going = false : keep_going;
}

std::string double_to_string(const double & value, int cut = 3)
{
	std::stringstream stream;
	
	stream.precision(cut);
	stream << std::fixed;
	stream << value;
	
	return stream.str();
}

int main()
{
	bool keep_going {true};
	size_t rounds {};
	
	while (keep_going)
	{
		++rounds;
		
		std::random_device random_dev;
		std::mt19937 mt(random_dev());
		std::uniform_int_distribution<int> random_numbers(-30, 30);
		std::uniform_int_distribution<int> random_operators(0, 3);
		
		double value_1 { static_cast<double>(random_numbers(mt)) };
		double value_2 { static_cast<double>(random_numbers(mt)) };
		double guess {};
		
		int random_operator_number { random_operators(mt) };
		
		const std::string operators[] { "+", "-", "*", "/" };
		const std::string random_operator { operators[random_operator_number] };
		
		const std::string math_question
				{
						double_to_string(value_1, 2)
						+ " " + random_operator + " " +
						double_to_string(value_2, 2) + " = ?"
				};
				
		std::cout << math_question << "\n";
		std::cout << "Answer: ";
		std::cin >> guess;
		
		switch (random_operator_number)
		{
		
			case 0:
			{
				if ((value_1 + value_2) == guess)
					std::cout << "Correct!" << std::endl;
				else
					std::cout << "Wrong!\n" << "The answer was: " << value_1 + value_2 << std::endl;
			} break;
			
			case 1:
			{
				if ((value_1 - value_2) == guess)
					std::cout << "Correct!" << std::endl;
				else
					std::cout << "Wrong!\n" << "The answer was: " << value_1 - value_2 << std::endl;
			}  break;
			
			case 2:
			{
				if ((value_1 * value_2) == guess)
					std::cout << "Correct!" << std::endl;
				else
					std::cout << "Wrong!\n" << "The answer was: " << value_1 * value_2 << std::endl;
			} break;
			
			case 3:
			{
				if (std::stod(double_to_string(value_1 / value_2)) == guess) // making sure we don't have to answer 0.466545 but 0.466 etc
					std::cout << "Correct!" << std::endl;
				else
					std::cout << "Wrong!\n" << "The answer was: " << std::stod(double_to_string(value_1 / value_2)) << std::endl;
			} break;
			
			default:
				break;
		}
		
		if (rounds == 3 || rounds == 6 || rounds == 9)
			if_quit(keep_going);
		else
		{
			//sleep(1);
			std::cout << std::endl;
		}
	}
}