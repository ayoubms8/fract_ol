/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:18:19 by alemsafi          #+#    #+#             */
/*   Updated: 2023/01/06 13:07:36 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	scroll(int key, int x, int y, t_strct *mn)
{
	if (key == SCROLL_OUT)
	{
		mn->leftz += (x * mn->xscale - mn->left + mn->leftz) / 10;
		mn->topz += (y * mn->yscale - mn->top + mn->topz) / 10;
		mn->xzoom = mn->xzoom + mn->xzoom / 20;
		update(mn);
	}
	else if (key == SCROLL_IN)
	{
		mn->leftz -= (x * mn->xscale - mn->left + mn->leftz) / 10;
		mn->topz -= (y * mn->yscale - mn->top + mn->topz) / 10;
		mn->xzoom = mn->xzoom - mn->xzoom / 20;
		update(mn);
	}
	else if (key == LEFT_CLICK)
	{
		if (mn->mod == 1)
			mn->mod = 0;
		else if (mn->mod == 0)
			mn->mod = 1;
		update(mn);
	}
	return (0);
}

int	key(int key, t_strct *mn)
{
	if (key == ESC)
		quit(mn);
	else if (key == PLUS)
	{
		mn->xzoom = mn->xzoom - mn->xzoom / 10;
		update(mn);
	}
	else if (key == MINUS)
	{
		mn->xzoom = mn->xzoom + mn->xzoom / 10;
		update(mn);
	}
	else if (key == COLOR)
		change_color_range(mn);
	else
		key2(key, mn);
	return (0);
}

void	change_color_range(t_strct *mn)
{
	mn->z.color1 += 0x123456;
	mn->z.color2 += 0x123456;
	mn->z.color3 += 0x123456;
	mn->z.color4 += 0x123456;
	mn->z.color5 += 0x123456;
	mn->z.color6 += 0x123456;
	mn->z.color7 += 0x123456;
	mn->z.color8 += 0x123456;
	mn->z.color9 += 0x123456;
	update(mn);
}

void	key2(int key, t_strct *mn)
{
	if (key == ARROW_UP)
	{
		mn->topz += mn->xzoom / 20;
		update(mn);
	}
	else if (key == ARROW_DOWN)
	{
		mn->topz -= mn->xzoom / 20;
		update(mn);
	}
	else if (key == ARROW_RIGHT)
	{
		mn->leftz -= mn->xzoom / 20;
		update(mn);
	}
	else if (key == ARROW_LEFT)
	{
		mn->leftz += mn->xzoom / 20;
		update(mn);
	}
}

int	quit(t_strct *mn)
{
	mlx_clear_window(mn->mlx, mn->win);
	mlx_destroy_window(mn->mlx, mn->win);
	exit(0);
	return (0);
}
