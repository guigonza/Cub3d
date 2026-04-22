/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:06:42 by rdrevar           #+#    #+#             */
/*   Updated: 2025/04/09 17:06:46 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*	
	The original function does not check whether dest is null
	or src is pointing to garbage.

	Returns the size of src even in it is not all copied
*/

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dsize)
{
	size_t	lcpy;

	lcpy = ft_strlen(src);
	if (dsize > 0)
	{
		while (*src && --dsize)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (lcpy);
}
