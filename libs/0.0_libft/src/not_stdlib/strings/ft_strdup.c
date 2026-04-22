/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:48:09 by rdrevar           #+#    #+#             */
/*   Updated: 2025/05/04 15:48:11 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*strdup;
	char	*p_strdup;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	strdup = malloc(s_len);
	if (!strdup)
		return (NULL);
	p_strdup = strdup;
	while (s_len--)
		*p_strdup++ = *s++;
	p_strdup[s_len] = '\0';
	return (strdup);
}
