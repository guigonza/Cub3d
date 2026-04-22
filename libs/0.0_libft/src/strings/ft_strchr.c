/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:46:56 by rdrevar           #+#    #+#             */
/*   Updated: 2025/05/04 15:46:59 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc == 0)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
