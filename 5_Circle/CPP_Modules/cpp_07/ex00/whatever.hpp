/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:36:23 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 21:36:23 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma  once

template <typename T>
void	swap(T &a, T &b) {
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(T &a, T &b) {
	if (a < b)
		return a;
	return b;
}

template <typename T>
T	max(T &a, T &b) {
	if (a > b)
		return a;
	return b;
}
