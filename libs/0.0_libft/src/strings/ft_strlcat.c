/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:14:29 by rdrevar           #+#    #+#             */
/*   Updated: 2025/04/09 17:14:35 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char		*ptr_dest;
	size_t		dlen;
	size_t		slen;
	size_t		remaining_space;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	ptr_dest = dest + dlen;
	remaining_space = size - dlen;
	if (size <= dlen)
		return (size + slen);
	while (*src && --remaining_space)
		*ptr_dest++ = *src++;
	*ptr_dest = '\0';
	return (dlen + slen);
}

// The destination must be at least len of dest + src + 1;

/* int main(void)
{
	char			dest[15] = "";
	const char		*src = "the cake is a lie !\0I'm hidden lol\r\n";

	size_t  size_of_dest = sizeof(dest);
	size_t  len_dest = ft_strlen(dest);

	printf("----------ORIGINAL-------------\n");
	printf("Size of dest:  %lu\n", sizeof(dest));
	printf("Length of dest: %zu\n", ft_strlen(dest));
	printf("Strng in dest dest: %s\n", dest);
	printf("Call function strlcat, return total: %lu\n", 
		strlcat(dest, src, sizeof(dest)));
	printf("Size of dest:  %lu\n", sizeof(dest));
	printf("Length of dest: %zu\n", ft_strlen(dest));
	printf("String in dest: %s\n", dest);

	char			i_dest[15] = "";
	const char		*i_src = "the cake is a lie !\0I'm hidden lol\r\n";

	size_t  size_of_idest = sizeof(i_dest);
	size_t  len_idest = ft_strlen(i_dest);
	printf("------------ MY IMPLEMENTATION -------------\n");
	printf("Size of dest:  %lu\n", size_of_idest);
	printf("Length of dest: %zu\n", len_idest);
	printf("Strng in dest dest: %s\n", i_dest);
	printf("Call function strlcat, return total: %lu\n", 
		ft_strlcat(i_dest, i_src, size_of_idest));
	printf("Size of dest:  %lu\n", size_of_idest);
	printf("Length of dest: %zu\n", ft_strlen(i_dest));
	printf("String in dest: %s\n", i_dest);
	return (0);
} */
