/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:36:12 by rdrevar           #+#    #+#             */
/*   Updated: 2025/04/23 16:36:15 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ptr_little;
	char	*ptr_big;
	size_t	remaining_len;

	if (*little == '\0')
		return ((char *)big);
	ptr_big = (char *)big;
	ptr_little = (char *)little;
	while (*big && len)
	{
		ptr_little = (char *)little;
		ptr_big = (char *)big;
		remaining_len = len;
		while ((*ptr_little == *ptr_big) && remaining_len--)
		{
			ptr_big++;
			ptr_little++;
			if (*ptr_little == '\0')
				return ((char *)big);
		}
		len--;
		big++;
	}
	return (NULL);
}
