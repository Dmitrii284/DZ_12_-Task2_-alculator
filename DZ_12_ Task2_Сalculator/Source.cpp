//#include<iostream>
//#include<string>
//#include <vector>
//#include <algorithm>
//
//int main()
//{
//	std::vector<std::string>numbers;
//
//	std::string input = "10 - 20";
//	std::string number1{" "};
//	std::string number2{" "};
//	char sign = '0';//Хранится знак действия
//	
//	std::any_of(input.begin(), input.end(), [&](const char& sign_fake)
//	{
//		if (sign_fake == '+' || sign_fake == '-' || sign_fake == '*' || sign_fake == '/' || sign_fake == '%')
//		{
//			sign = sign_fake;
//			return true;
//		}
//		return false;
//	});
//
//	auto firstNumberIterator = std::find_if(input.begin(), input.end(), isdigit);
//
//	if (firstNumberIterator == input.end()) exit(EXIT_FAILURE);
//
//	number1 += *firstNumberIterator;
//
//	firstNumberIterator++;
//	
//	while(true)
//	{
//		if (!isdigit(*firstNumberIterator))
//			break;
//		number1 += *firstNumberIterator;
//		firstNumberIterator++;
//	}
//
//	auto secondNumberIterator = std::find_if(firstNumberIterator, input.end(), isdigit);
//
//	if (secondNumberIterator == input.end()) exit(EXIT_FAILURE);
//
//	number2 += *secondNumberIterator;
//
//	secondNumberIterator++;
//
//	while (true)
//	{
//		if (!isdigit(*secondNumberIterator))
//			break;
//		number2 += *secondNumberIterator;
//		secondNumberIterator++;
//		if (secondNumberIterator == input.end()) break;
//	}
//	std::cout << number1 << ' ' << sign << ' ' << number2;
//
//
//
//	return 0;
//}

/*
Задание 2
создать класс калькулятор который позволит выполнять
арифметические операции над числами
комментарии:
все данные в класс и его объекты приходят извне
в классе не хранится информации
операции требуются для бух-учёта
+ - * / %


*/
// Второй способ решения

/*if (!getline(expression, number, ' '))
{
	while (getline(expression, number, sign))
	{
		int value = stoi(number);
		calculator.action.emplace_back(value);
	}
}

/*void Show()
	{
		for(auto &it :action)
			std::cout << "Expression-> " << action << ' = ';
	}*/

#include<iostream>
#include<vector>
#include<sstream>
#include <algorithm>

class Calculator
{
public:
	// Перегрузка прератора ввода	
	friend  std::istream& operator>>(std::istream& in, Calculator& calculator)
	{
		std::string input;
		in >> input;
		
		char sign = '0';//Хранится знак действия

		std::any_of(input.begin(), input.end(), [&](const char& sign_fake)
		{
			if (sign_fake == '+' || sign_fake == '-' || sign_fake == '*' || sign_fake == '/' || sign_fake == '%')
			{
				sign = sign_fake;
				return true;
			}
			return false;
		});

		std::istringstream input2(input);

		std::vector<int>vec;

		for (std::string line; std::getline(input2, line, sign);)
			vec.emplace_back(std::stoi(line));
		int answer{ 0 };

		switch (sign)
		{
			case '+':
				for (const auto& num : vec)
					answer += num;
				break;
			case '-':
				for (const auto& num : vec)
					answer -= num;
				break;
			case '*':
				answer = 1;
					for (const auto& num : vec)
						answer *= num;
					break;
			case '/':
				answer = 1;
				for (const auto& num : vec)
					answer /= num;
				break;
			case '%':
				answer = 1;
				for (const auto& num : vec)
					answer %= num;
				break;
			default:
				std::cout << "WARNING: Sign is not declared!" << std::endl;
				exit(EXIT_FAILURE);
			break;
		}

		std::cout << answer;
		
		return in;
	}
};

std::istream& operator>>(std::istream& in, Calculator& calculator);

int main()
{
	setlocale(LC_ALL, "Rus");
	Calculator cal;
	std::cout << "Enter expression: ";
	
	std::cin >> cal;
	

	return 0;
}