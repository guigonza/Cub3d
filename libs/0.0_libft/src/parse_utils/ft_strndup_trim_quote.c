/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_trim_quote.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:12:59 by rdrevar           #+#    #+#             */
/*   Updated: 2025/09/17 18:13:03 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	skip_quote(char c, int *in_quote, char *quote_char);

char	*ft_strndup_trim_quote(const char *start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;
	int		in_quote;
	char	quote_char;

	i = 0;
	j = 0;
	in_quote = 0;
	quote_char = '\0';
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		if (skip_quote(start[i], &in_quote, &quote_char))
			i++;
		result[j++] = start[i++];
	}
	result[j] = '\0';
	return (result);
}

int	skip_quote(char c, int *in_quote, char *quote_char)
{
	if (c == '\0')
		return (0);
	if (*in_quote)
	{
		if (c == *quote_char)
		{
			*in_quote = 0;
			return (1);
		}
	}
	else
	{
		if (c == '\'' || c == '"')
		{
			*in_quote = 1;
			*quote_char = c;
			return (1);
		}
	}
	return (0);
}
