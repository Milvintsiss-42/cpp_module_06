/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:40:23 by ple-stra          #+#    #+#             */
/*   Updated: 2024/02/16 19:50:55 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <stdint.h>

class Serializer {
private:
	~Serializer();
public:
	Serializer();
	Serializer(Serializer const &src);

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

	Serializer &operator=(Serializer const &rhs);
};
