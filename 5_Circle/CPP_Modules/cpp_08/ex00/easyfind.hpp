/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:01:30 by takwak            #+#    #+#             */
/*   Updated: 2025/05/16 19:53:27 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
typename T::iterator	easyfind(T &container, int to_find) {
	typename	T::iterator it;
	for (it = container.begin(); it != container.end(); it++) {
		if (*it == to_find)
			return it;
	}
	return container.end();
}
