/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:38:43 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/16 17:02:08 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>

class ScalarConverter {
private:
	~ScalarConverter();
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &src);

	static void convert(std::string const literal);

	ScalarConverter &operator=(ScalarConverter const &rhs);
};
