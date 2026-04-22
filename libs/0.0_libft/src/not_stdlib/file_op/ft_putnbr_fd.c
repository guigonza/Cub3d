/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:37:03 by rdrevar           #+#    #+#             */
/*   Updated: 2025/05/04 15:37:05 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	long	long_nbr;

	long_nbr = nbr;
	if (long_nbr < 0)
	{
		ft_putchar_fd('-', fd);
		long_nbr = -long_nbr;
	}
	if (long_nbr >= 10)
		ft_putnbr_fd((long_nbr / 10), fd);
	ft_putchar_fd(((long_nbr % 10) + 48), fd);
}

/* int main(void)
{
	int MAX_NUMBER = 2147483647;
	int MIN_NUMBER= - 2147483648;

	ft_putnbr_fd(MIN_NUMBER, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(-6547, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);
	
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(21474, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(MAX_NUMBER, 1);
	write(1, "\n", 1);

	return(0);
} */
