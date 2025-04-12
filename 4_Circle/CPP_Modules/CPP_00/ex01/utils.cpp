/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyoengsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 00:49:42 by takwak            #+#    #+#             */
/*   Updated: 2025/04/13 00:49:45 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_string(char *str, int size)
{
	for (int i = 0; i < size; i++)
		str[i] = '\0';
}

void	strcpy(char *dst, const char *src)
{
	for (int i = 0; src[i]; i++)
		dst[i] = src[i];
}
