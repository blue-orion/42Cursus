/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:00:56 by takwak            #+#    #+#             */
/*   Updated: 2025/05/15 18:03:09 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Data {
private:
	int	a;
	int	b;
	int	c;

public:
	Data();
	~Data();
	Data(const Data& other);
	Data&	operator=(const Data& other);
};
