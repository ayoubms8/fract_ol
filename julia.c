/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:42:20 by alemsafi          #+#    #+#             */
/*   Updated: 2023/01/06 16:29:15 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_strct *mn)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mn->z.real = x * mn->xscale - mn->left;
			mn->z.img = y * mn->yscale - mn->top;
			loop(mn, &mn->z);
			put_pixels(mn, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mn->mlx, mn->win, mn->img, 0, 0);
}

int	mousemov(int x, int y, t_strct *mn)
{
	if (mn->mod == 0)
	{
		mn->cx = x * mn->xscale - mn->left;
		mn->cy = y * mn->yscale - mn->top;
		update(mn);
	}
	else if (mn->mod == 1)
		update(mn);
	return (0);
}
