/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:55:28 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/16 16:43:51 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

static bool is_char(std::string const literal)
{
	return (literal.length() == 1 && std::isprint(*(literal.begin())));
}

static bool is_int(std::string const literal)
{
    std::string::const_iterator it = literal.begin();
	if (*it == '-')
		it++;
    while (it != literal.end() && std::isdigit(*it))
		++it;
    return (it == literal.end());
}

static bool is_floating_point_number(std::string const literal, bool is_float)
{
	std::string s(literal);
	if (is_float)
	{
		if (*(literal.end() - 1) != 'f')
			return false;
		s.erase(s.length() - 1);
	}

	if (s == "inf" || s == "+inf" || s == "-inf" || s == "nan")
		return true;

	int dot_count = 0;
	std::string::const_iterator it = s.begin();
	if (*it == '-')
		it++;
    while (it != s.end())
	{
		if (*it == '.')
			dot_count++;
		else if (!std::isdigit(*it))
			return false;
		++it;
	}
	if (dot_count != 1 || *(s.end() - 1) == '.')
		return false;
    return true;
}

static int string_to_int(std::string const s)
{
	int i;
	std::istringstream(s) >> i;
	return (i);
}

static float string_to_float(std::string const s)
{
	if (s == "nanf")
		return (std::numeric_limits<float>::quiet_NaN());
	else if (s == "inff" || s == "+inff")
		return (std::numeric_limits<float>::infinity());
	else if (s == "-inff")
		return (- std::numeric_limits<float>::infinity());

	float f;
	std::istringstream(s) >> f;
	return (f);
}

static double string_to_double(std::string const s)
{
	if (s == "nan")
		return (std::numeric_limits<double>::quiet_NaN());
	else if (s == "inf" || s == "+inf")
		return (std::numeric_limits<double>::infinity());
	else if (s == "-inf")
		return (- std::numeric_limits<double>::infinity());

	double d;
	std::istringstream(s) >> d;
	return (d);
}

static std::string float_to_string(float const f)
{
	std::string s;
	std::ostringstream oss;
	float tmp;

	oss << f;
	s = oss.str();
	if (modff(f, &tmp) == 0.0
		&& f != std::numeric_limits<float>::infinity()
		&& f != -std::numeric_limits<float>::infinity())
		s += ".0";
	s += "f";
	return (s);
}

static std::string double_to_string(double const d)
{
	std::string s;
	std::ostringstream oss;
	double tmp;

	oss << d;
	s = oss.str();
	if (modf(d, &tmp) == 0.0
		&& d != std::numeric_limits<double>::infinity()
		&& d != -std::numeric_limits<double>::infinity())
		s += ".0";
	return (s);
}

static void print_char_convertion(std::string const literal)
{
	std::cout << "This is a char." << std::endl;

	char c = *(literal.begin());

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << float_to_string(static_cast<float>(c)) << std::endl;
	std::cout << "double: " << double_to_string(static_cast<double>(c)) << std::endl;
}

static void print_int_convertion(std::string const literal)
{
	std::cout << "This is an int." << std::endl;

	int i = string_to_int(literal);

	if ((static_cast<double>(i)) == string_to_double(literal))
	{
		if (std::isprint(static_cast<char>(i)))
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << float_to_string(static_cast<float>(i)) << std::endl;
		std::cout << "double: " << double_to_string(static_cast<double>(i)) << std::endl;
	}
	else
	{
		std::cout << "Overflow detected." << std::endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
	}
}

static void print_float_convertion(std::string const literal)
{
	std::cout << "This is a float." << std::endl;

	float f = string_to_float(literal);

	if (f <= std::numeric_limits<int>::max()
		&& f >= std::numeric_limits<int>::min())
	{
		if (std::isprint(static_cast<char>(f)))
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << float_to_string(f) << std::endl;
	std::cout << "double: " << double_to_string(static_cast<double>(f)) << std::endl;
}

static void print_double_convertion(std::string const literal)
{
	std::cout << "This is a double." << std::endl;

	double d = string_to_double(literal);

	if (d <= std::numeric_limits<int>::max()
		&& d >= std::numeric_limits<int>::min())
	{
		if (std::isprint(static_cast<char>(d)))
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << float_to_string(static_cast<float>(d)) << std::endl;
	std::cout << "double: " << double_to_string(d) << std::endl;
}

// This is not straightforward at all but the 42 subject rules are not clear.
// So this implementation complies to all possible interpretations of the
// subject rules.
void ScalarConverter::convert(std::string const literal)
{

	if (is_floating_point_number(literal, false))
		print_double_convertion(literal);
	else if (is_floating_point_number(literal, true))
		print_float_convertion(literal);
	else if (is_int(literal))
		print_int_convertion(literal);
	else if (is_char(literal))
		print_char_convertion(literal);
	else
		std::cerr << "Literal isn't any of the defined scalars." << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return *this;
}
