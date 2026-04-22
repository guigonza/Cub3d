/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:19:26 by rdrevar           #+#    #+#             */
/*   Updated: 2026/04/21 19:21:11 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_valid_int(const char *str)
{
	long	val;
	int		sign;

	val = 0;
	sign = 1;
	if (!str || !*str)
		return (0);
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign = -1;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		val = val * 10 + (*str - '0');
		if ((sign == 1 && val > INT_MAX) || (sign == -1 && (-val) < INT_MIN))
			return (0);
		str++;
	}
	return (1);
}
