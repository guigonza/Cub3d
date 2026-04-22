/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:51:17 by rdrevar           #+#    #+#             */
/*   Updated: 2025/05/04 15:51:24 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	s += s_len;
	if ((unsigned char)c == '\0')
		return ((char *)s);
	while (s_len-- && s--)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
	}
	return (NULL);
}
