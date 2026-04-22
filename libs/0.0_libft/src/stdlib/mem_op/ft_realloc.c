/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdrevar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:37:41 by rdrevar           #+#    #+#             */
/*   Updated: 2025/07/16 18:37:47 by rdrevar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*re_ptr;

	re_ptr = malloc(20);
	if (!re_ptr)
		return (NULL);
	if (ptr != NULL)
	{
		if (old_size <= new_size)
		{
			ft_memcpy(re_ptr, ptr, old_size);
		}
		else
		{
			ft_memcpy(re_ptr, ptr, new_size);
		}
	}
	free(ptr);
	return (re_ptr);
}
