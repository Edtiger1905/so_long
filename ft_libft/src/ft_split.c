/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 00:00:00 by epandele          #+#    #+#             */
/*   Updated: 2025/11/08 22:37:53 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	count_words(const char *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			++s;
		if (*s)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
	}
	return (count);
}

static void	free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	array = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			++s;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		array[i] = ft_substr(s, 0, len);
		if (!array[i++])
			return (free_array (array, i - 1), (char **) NULL);
		s += len;
	}
	return (array[i] = NULL, array);
}
