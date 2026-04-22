/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:27:12 by rdrevar           #+#    #+#             */
/*   Updated: 2025/10/02 13:27:13 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	parse_integer(const char **s, double *result)
{
	while (ft_isdigit(**s))
	{
		*result = *result * 10.0 + (**s - '0');
		(*s)++;
	}
}

static void	parse_float(const char **s, double *result, double *divisor)
{
	if (**s == '.')
	{
		(*s)++;
		*divisor = 10.0;
		while (ft_isdigit(**s))
		{
			*result += (**s - '0') / *divisor;
			*divisor *= 10.0;
			(*s)++;
		}
	}
}

double	ft_strtod(const char *str, char **endptr)
{
	const char		*s;
	double			result;
	int				sign;
	double			divisor;

	s = str;
	result = 0.0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		s++;
	set_sign(&s, &sign);
	parse_integer(&s, &result);
	parse_float(&s, &result, &divisor);
	if (endptr)
		*endptr = (char *)s;
	return (result * sign);
}
