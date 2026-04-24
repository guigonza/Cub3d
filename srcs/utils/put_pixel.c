/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:50:12 by jomarti3          #+#    #+#             */
/*   Updated: 2026/04/24 11:17:10 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int c)
{
	if (x < 0 || y < 0 || x >= img->w || y >= img->h)
		return ;
	*(unsigned int *)(img->addr + y * img->line + x * (img->bpp / 8)) = c;
}
