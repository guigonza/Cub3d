/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:17:42 by rdrevar           #+#    #+#             */
/*   Updated: 2025/05/04 15:17:44 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_nbr_len(long long_n)
{
	int	len;

	len = 0;
	if (long_n <= 0)
		len++;
	while (long_n)
	{
		long_n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	long_n;
	int		nstr_len;
	char	*num_str;

	long_n = n;
	nstr_len = ft_nbr_len(long_n);
	num_str = (char *)malloc(sizeof(char) * (nstr_len + 1));
	if (!num_str)
		return (NULL);
	num_str[nstr_len] = '\0';
	if (long_n == 0)
		num_str[0] = '0';
	if (long_n < 0)
	{
		num_str[0] = '-';
		long_n = -long_n;
	}
	while (long_n > 0)
	{
		num_str[--nstr_len] = '0' + (long_n % 10);
		long_n /= 10;
	}
	return (num_str);
}
/* 
int	main(void)
{
	//printf("%d\n", ft_nbr_len(-12345678));
	printf("%s\n", ft_itoa(-12345678));
	return (0);
} */
