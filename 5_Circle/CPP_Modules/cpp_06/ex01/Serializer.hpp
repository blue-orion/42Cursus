/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:56:37 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 18:01:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer& other);
	Serializer&	operator=(const Serializer& other);

public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t	raw);
};
