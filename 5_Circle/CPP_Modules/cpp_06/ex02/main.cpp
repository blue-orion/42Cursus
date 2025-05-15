/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:43:58 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 19:52:48 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void) {
	Base	*ptr = generate();
	identify(ptr);

	Base	&ref = *generate();
	identify(ref);

	delete ptr;
	delete &ref;
}
