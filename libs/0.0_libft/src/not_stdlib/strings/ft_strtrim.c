/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:04:49 by rdrevar           #+#    #+#             */
/*   Updated: 2025/05/04 15:04:50 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	in_set(const char *set, char c)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

static char	*ft_strtrim_start(const char *s1, const char *set)
{
	while (*s1 && in_set(set, *s1))
		s1++;
	return ((char *)s1);
}

static char	*ft_strtrim_end(char *start, const char *set)
{
	char	*end;

	end = start + ft_strlen(start);
	while (end > start && in_set(set, *(end - 1)))
		end--;
	return ((char *)end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	char	*start;
	char	*end;
	char	*result;

	start = ft_strtrim_start(s1, set);
	end = ft_strtrim_end(start, set);
	len = end - start;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, start, len + 1);
	result[len] = '\0';
	return (result);
}

/* int	main(void)
{
	char *s1 = "ababaaaMy name is Simonbbaaabba";
	char *set = "ab";
	char *trimmed = ft_strtrim(s1, set);

	if (trimmed)
		printf("Trimmed: %s\n", trimmed);
	else
		printf("Not trimmed\n");
	return (0);
} */
