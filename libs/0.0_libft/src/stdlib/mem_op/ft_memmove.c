/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:39:13 by rdrevar           #+#    #+#             */
/*   Updated: 2025/04/15 15:39:15 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// If source is before dest and they overlap, copy backwards
// Copy forwards when source is after or equal to dest

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	unsigned char		*ptr_src;

	if (!src && !dest)
		return (dest);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_src < ptr_dest)
	{
		ptr_dest += n;
		ptr_src += n;
		while (n--)
			*(--ptr_dest) = *(--ptr_src);
	}
	else
	{
		while (n--)
			*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}

/* 
int main()
{
	char data[] = "1234567890";

	// Overlapping regions
	ft_memmove(data + 2, data, 5);
	// Output: "1212345890"
	printf("%s\n", data);  
	return 0;
} */
