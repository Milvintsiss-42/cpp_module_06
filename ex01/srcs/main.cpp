/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:12 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/16 19:53:35 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

static void print_data(Data data)
{
	std::cout << "Content of Data :" << std::endl;
	std::cout << "b :" << data.b << std::endl;
	std::cout << "c :" << data.c << std::endl;
	std::cout << "i :" << data.i << std::endl;
	std::cout << "d :" << data.d << std::endl;
	std::cout << "f :" << data.f << std::endl;
}

int	main()
{
	Data data;

	data.b = false;
	data.c = '*';
	data.i = 42;
	data.d = 42.42;
	data.f = 42.43;

	print_data(data);

	Data data2 = *Serializer::deserialize(Serializer::serialize(&data));

	std::cout << std::endl;
	print_data(data2);

	return (0);
}
