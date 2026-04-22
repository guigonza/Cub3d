/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:12:40 by rdrevar           #+#    #+#             */
/*   Updated: 2025/09/17 18:12:44 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen_quote(const char *s, char delimiter)
{
	size_t	len;
	int		in_quote;
	int		quote_char;

	if (delimiter == '\0')
		return (0);
	len = 0;
	in_quote = 0;
	quote_char = '\0';
	while (s[len])
	{
		if (!in_quote && (s[len] == '\'' || s[len] == '"'))
		{
			in_quote = 1;
			quote_char = s[len];
		}
		else if (in_quote && s[len] == quote_char)
		{
			in_quote = 0;
		}
		else if (!in_quote && s[len] == delimiter)
			break ;
		len++;
	}
	return (len);
}
