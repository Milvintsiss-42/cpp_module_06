/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:12 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/16 20:52:16 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <stdlib.h>

static Base *generate(void)
{
	int base_index = rand() % 3;

	switch (base_index)
	{
		case 0:
			{
				std::cout << "A class of type 'A' as been generated."
					<< std::endl;
				return new A();
			}
		case 1:
			{
				std::cout << "A class of type 'B' as been generated."
					<< std::endl;
				return new B();
			}
		case 2:
			{
				std::cout << "A class of type 'C' as been generated."
					<< std::endl;
				return new C();
			}
		default:
			return (NULL);
	}
}

static void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Class of type 'A' identified from Base pointer."
			<< std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Class of type 'B' identified from Base pointer."
			<< std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Class of type 'C' identified from Base pointer."
			<< std::endl;
	else
		std::cerr << "Unable to identify class." << std::endl;
}

static void identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "Class of type 'A' identified from Base pointer."
			<< std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "Class of type 'B' identified from Base pointer."
			<< std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "Class of type 'C' identified from Base pointer."
			<< std::endl;
	}
	catch (std::exception &e)
	{}
}

int	main()
{
	srand((unsigned)time(NULL));

	Base *base;
	for (int i = 0; i < 10; i++)
	{
		base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;

		delete base;
	}
	return (0);
}
