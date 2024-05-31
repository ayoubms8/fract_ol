/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:09:01 by alemsafi          #+#    #+#             */
/*   Updated: 2023/01/06 13:12:53 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tricorn(t_strct *mn)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mn->cx = x * mn->xscale - mn->left;
			mn->cy = y * mn->yscale - mn->top;
			mn->z.real = x * mn->xscale - mn->left;
			mn->z.img = y * mn->yscale - mn->top;
			triloop(mn, &mn->z);
			put_pixels(mn, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mn->mlx, mn->win, mn->img, 0, 0);
}

void	triloop(t_strct *mn, t_num *z)
{
	float	temp;

	mn->count = 0;
	while ((z->real * z->real + z->img * z->img < 4) && mn->count < MAXCNT)
	{
		temp = z->real * z->real - z->img * z->img + mn->cx;
		z->img = -2 * z->real * z->img + mn->cy;
		z->real = temp;
		mn->count++;
	}
}
