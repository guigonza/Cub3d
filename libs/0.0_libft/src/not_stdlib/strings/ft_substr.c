/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:55:17 by rdrevar           #+#    #+#             */
/*   Updated: 2025/05/04 14:55:21 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*substr;
	char	*p_substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)s + start;
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	p_substr = substr;
	p_substr[len] = '\0';
	while (*str && len--)
		*p_substr++ = *str++;
	return (substr);
}
