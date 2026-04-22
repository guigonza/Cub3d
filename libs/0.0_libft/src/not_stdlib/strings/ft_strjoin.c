/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:01:02 by rdrevar           #+#    #+#             */
/*   Updated: 2025/05/04 15:01:05 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	total_len;
	size_t	s1_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	total_len = s1_len + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(total_len);
	if (!strjoin)
		return (NULL);
	ft_strlcpy(strjoin, s1, s1_len + 1);
	ft_strlcat(strjoin, s2, total_len + 1);
	return (strjoin);
}
