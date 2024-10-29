/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takwak <takwak@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:43:11 by takwak            #+#    #+#             */
/*   Updated: 2024/10/27 23:43:11 by takwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	total_len;
	size_t	s1_len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	s1_len = ft_strlen(s1);
	total_len = s1_len + ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (total_len + 1));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		if (i < s1_len)
			*(joined + i) = *(s1 + i);
		else
			*(joined + i) = *(s2 + i - s1_len);
		i++;
	}
	*(joined + i) = '\0';
	return (joined);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (*(s + len) != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*cpy;
	size_t	i;

	if (s == NULL)
		return (0);
	cpy = (char *)malloc(sizeof(char) * (n + 1));
	if (cpy == NULL)
		return (0);
	i = 0;
	while (i < n && *s)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
