/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <rdrevar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 19:31:45 by rdrevar           #+#    #+#             */
/*   Updated: 2026/04/21 19:39:16 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
//#include "ft_printf_utils.h"

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>

# include "libft.h"

int	is_valid_base(const char *base)
{
	size_t	i;
	size_t	j;

	if (ft_strlen((char *)base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*ft_utoa_base(uintmax_t number, const char *base)
{
	size_t		len;
	char		buf[65];
	size_t		i;
	char		*res;
	size_t		j;

	if (!is_valid_base(base))
		return (NULL);
	len = ft_strlen((char *)base);
	i = 0;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		buf[i++] = base[number % len];
		number /= len;
	}
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (i-- > 0)
		res[j++] = buf[i];
	res[j] = '\0';
	return (res);
}
