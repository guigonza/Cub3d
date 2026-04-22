/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:21:34 by rdrevar           #+#    #+#             */
/*   Updated: 2025/05/04 15:21:39 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mstr;
	size_t			mstr_len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	mstr_len = ft_strlen(s);
	mstr = malloc((mstr_len + 1) * sizeof(char));
	if (!mstr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mstr[i] = (*f)(i, s[i]);
		i++;
	}
	mstr[i] = '\0';
	return (mstr);
}
/* 
char shift_char(unsigned int i, char c)
{
	return 'a';
}

int main(void)
{
	const char *original = "abcdef";
	char *mapped;

	mapped = ft_strmapi(original, shift_char);
	if (!mapped)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}

	printf("Original: %s\n", original);
	printf("Mapped:   %s\n", mapped);

	free(mapped);
	return 0;
} */
