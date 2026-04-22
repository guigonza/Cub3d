/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:09:20 by rdrevar           #+#    #+#             */
/*   Updated: 2025/09/08 11:49:55 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_str(char const *str, int delimiter)
{
	int		flag;
	size_t	str_count;

	flag = 1;
	str_count = 0;
	while (*str)
	{
		if (*str == delimiter)
			flag = 1;
		else if (flag)
		{
			flag = 0;
			str_count++;
		}
		str++;
	}
	return (str_count);
}

size_t	ft_strlen_delimiter(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && c != *s++)
		len++;
	return (len);
}

static int	ft_strv_malloc(char **str_v, int position, size_t buffer)
{
	str_v[position] = malloc(buffer);
	if (!str_v[position])
	{
		while (position)
			free(str_v[--position]);
		free(str_v);
		return (0);
	}
	return (1);
}

static int	ft_fill(char **str_v, char const *str, int delimiter)
{
	size_t	str_len;
	int		position;

	position = 0;
	while (*str)
	{
		if (*str == delimiter)
			str++;
		str_len = ft_strlen_delimiter(str, delimiter);
		if (str_len)
		{
			if (ft_strv_malloc(str_v, position, str_len + 1))
			{
				ft_strlcpy(str_v[position], str, str_len + 1);
				position++;
				str += str_len;
			}
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_str;
	char	**str_v;

	if (!s)
		return (NULL);
	num_str = ft_count_str(s, c);
	str_v = malloc((num_str + 1) * sizeof(char *));
	if (!str_v)
		return (NULL);
	str_v[num_str] = 0;
	if (ft_fill(str_v, s, c))
		return (NULL);
	return (str_v);
}
