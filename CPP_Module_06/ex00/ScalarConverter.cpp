#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <string>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

void ScalarConverter::detectType(const std::string &literal, int &type)
{
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		type = CHAR;
	else if (literal == "nan" || literal == "nanf" ||
             literal == "inf" || literal == "+inf" || literal == "-inf" ||
             literal == "inff" || literal == "+inff" || literal == "-inff")
		type = SPECIAL;
	else if (literal.find('.') != std::string::npos)
	{
		if (literal[literal.length() - 1] == 'f')
			type = FLOAT;
		else
			type = DOUBLE;
	}
	else
	{
		try
		{
			char* endptr;
			std::strtol(literal.c_str(), &endptr, 10);
			if (*endptr == '\0')
				type = INT;
			else
				type = INVALID;
		}
		catch (...)
		{
			type = INVALID;
		}
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	int type = INVALID;
	ScalarConverter::detectType(literal, type);

	switch (type)
	{
	case CHAR:
		ScalarConverter::printChar(literal);
		break;
	case INT:
		ScalarConverter::printInt(literal);
		break;
	case FLOAT:
		ScalarConverter::printFloat(literal);
		break;
	case DOUBLE:
		ScalarConverter::printDouble(literal);
		break;
	case SPECIAL:
		ScalarConverter::printSpecial(literal);
		break;
	default:
		std::cout << "Invalid literal: " << literal << std::endl;
	}
}

void ScalarConverter::printChar(const std::string &literal)
{
	std::cout << "char: " << literal << std::endl;
	std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
}

void ScalarConverter::printInt(const std::string &literal)
{
	int value = std::atoi(literal.c_str());

	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::printDouble(const std::string &literal)
{
	double value = std::atof(literal.c_str());

	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
}

void ScalarConverter::printFloat(const std::string &literal)
{
	float value = std::atof(literal.c_str());

	if (value >= 32 && value <= 126)
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << value << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::printSpecial(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
	{
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

