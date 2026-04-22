/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:28:55 by rdrevar           #+#    #+#             */
/*   Updated: 2025/10/03 13:28:57 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

#include "libft.h"

static void	set_sign(const char **s, int *sign)
{
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			*sign = -1;
		(*s)++;
	}
}

static int	overflow_detection(int sign, int result, int digit)
{
	if (sign == 1 && (result > (INT_MAX - digit) / 10))
		return (1);
	if (sign == -1 && result > ((-(long)INT_MIN - digit) / 10))
		return (1);
	return (0);
}

// Returns 1 on success, 0 on error
// Skip whitespace
// Must have at least one digit
// Overflow detection
// If there's any non-digit characters left, it's invalid
int	ft_strtol(const char *str, long *out)
{
	int		sign;
	long	result;
	int		i;
	int		digit;

	sign = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	set_sign(&str, &sign);
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		digit = str[i] - '0';
		if (overflow_detection(sign, result, digit))
			return (0);
		result = result * 10 + digit;
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*out = result * sign;
	return (1);
}
