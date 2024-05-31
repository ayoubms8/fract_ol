/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:04:36 by alemsafi          #+#    #+#             */
/*   Updated: 2023/01/06 16:57:53 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zinit(t_strct *mn)
{
	mn->yzoom = mn->xzoom / 2;
	mn->left = mn->xzoom / 2 + mn->leftz;
	mn->top = mn->yzoom / 2 + mn->topz;
	mn->xscale = mn->xzoom / WIDTH;
	mn->yscale = mn->yzoom / HEIGHT;
}

void	update(t_strct *mn)
{
	zinit(mn);
	mlx_clear_window(mn->mlx, mn->win);
	if (mn->fractal == 1)
		mandel(mn);
	else if (mn->fractal == 2)
		julia(mn);
	else if (mn->fractal == 3)
		tricorn(mn);
}

void	assign_colors(t_strct *mn)
{
	mn->z.color1 = 0x000000;
	mn->z.color2 = 0x280046;
	mn->z.color3 = 0x46006E;
	mn->z.color4 = 0x640096;
	mn->z.color5 = 0x000000;
	mn->z.color6 = 0x8C00BE;
	mn->z.color7 = 0xAA00E1;
	mn->z.color8 = 0xC700FF;
	mn->z.color9 = 0x640096;
}

int	sm_scale(float	*scale)
{
	*scale = *scale / 10;
	return (1);
}

float	ft_atof(char *str)
{
	float	acc;
	int		afterdot;
	float	scale;
	int		sign;

	acc = 0;
	afterdot = 0;
	scale = 1;
	sign = 1;
	if (*str && (*str == '-' || *str == '+'))
		if (*str++ == '-')
			sign = -1;
	while (*str && (ft_isdigit(*str) || *str == '.'))
	{
		if (afterdot && sm_scale(&scale))
			acc = acc + (*str - '0') * scale;
		else if (*str == '.')
			afterdot++;
		else
			acc = acc * 10 + (*str - '0');
		str++;
	}
	return (sign * acc);
}
