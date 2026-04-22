/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:12:10 by rdrevar           #+#    #+#             */
/*   Updated: 2025/09/17 18:12:23 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"

static size_t	ft_count_str_quote(char const *str, int delimiter);
static int		ft_fill_quote(char **str_v, char const *str, int delimiter);
static int		update_in_quote(char c, int *in_quote, char *quote_char);
static int		ft_recursive_free_strv(char **str_v, int position);

char	**ft_split_quote(char const *s, char c)
{
	size_t	num_str;
	char	**str_v;

	if (!s)
		return (NULL);
	num_str = ft_count_str_quote(s, c);
	str_v = malloc((num_str + 1) * sizeof(char *));
	if (!str_v)
		return (NULL);
	str_v[num_str] = 0;
	if (ft_fill_quote(str_v, s, c))
		return (NULL);
	return (str_v);
}

static size_t	ft_count_str_quote(char const *str, int delimiter)
{
	int			flag;
	size_t		str_count;
	int			in_quote;
	char		quote_char;

	if (delimiter == '\0')
		return (0);
	flag = 1;
	str_count = 0;
	in_quote = 0;
	quote_char = '\0';
	while (*str)
	{
		update_in_quote(*str, &in_quote, &quote_char);
		if (!in_quote && *str == delimiter)
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

static int	ft_fill_quote(char **str_v, char const *str, int delimiter)
{
	size_t	len;
	int		pos;

	pos = 0;
	while (*str)
	{
		while (*str == delimiter)
			str++;
		if (*str == '\0')
			break ;
		len = ft_strlen_quote(str, delimiter);
		str_v[pos] = ft_strndup_trim_quote(str, len);
		if (!str_v[pos])
			ft_recursive_free_strv(str_v, pos);
		str += len;
		pos++;
	}
	return (0);
}

/* helper function for count_str_quote*/
static int	update_in_quote(char c, int *in_quote, char *quote_char)
{
	if (c == '\0')
		return (0);
	if (*in_quote)
	{
		if (c == *quote_char)
			*in_quote = 0;
	}
	else
	{
		if (c == '\'' || c == '"')
		{
			*in_quote = 1;
			*quote_char = c;
		}
	}
	return (*in_quote);
}

static int	ft_recursive_free_strv(char **str_v, int position)
{
	while (position)
		free(str_v[--position]);
	free(str_v);
	return (1);
}
