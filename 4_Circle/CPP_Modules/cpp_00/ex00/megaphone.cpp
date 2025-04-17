/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 19:16:58 by takwak            #+#    #+#             */
/*   Updated: 2025/04/12 18:29:24 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char	*to_upper(char *s)
{
	for (int i = 0; s[i]; i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = s[i] - 32;
	}
	return (s);
}

int	main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		std::cout << to_upper(argv[i]);
	}
	std::cout << std::endl;
	return 0;
}
