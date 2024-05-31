/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:42:41 by alemsafi          #+#    #+#             */
/*   Updated: 2023/01/06 17:02:05 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *av[])
{
	t_strct	mn;

	if ((argc != 2 && argc != 4) || (ft_atoi(av[1]) != 1 && ft_atoi(av[1]) != 2
			&& ft_atoi(av[1]) != 3) || (argc == 4 && (ft_atoi(av[1]) == 1
				|| ft_atoi(av[1]) == 3)))
		usage();
	else
	{
		init_mn(&mn);
		mn.mlx = mlx_init();
		mn.win = mlx_new_window(mn.mlx, WIDTH, HEIGHT, "fractol");
		mn.img = mlx_new_image(mn.mlx, WIDTH, HEIGHT);
		mn.pixels = (uint32_t *)mlx_get_data_addr(mn.img, &mn.pixel_bits,
				&mn.line_bytes, &mn.endian);
		mn.fractal = ft_atoi(av[1]);
		if (mn.fractal == 2 && argc == 4)
			do_fractal(mn, ft_atof(av[2]), ft_atof(av[3]));
		else
			do_fractal(mn, 0, 0);
		mlx_hook(mn.win, 2, 0, key, &mn);
		mlx_hook(mn.win, 4, 0, scroll, &mn);
		mlx_hook(mn.win, 6, 0, mousemov, &mn);
		mlx_hook(mn.win, ON_DESTROY, 0, quit, &mn);
		mlx_loop(mn.mlx);
	}
}

void	init_mn(t_strct *mn)
{
	assign_colors(mn);
	mn->mod = 0;
	mn->xzoom = 4.00;
	mn->leftz = 0;
	mn->topz = 0;
	zinit(mn);
}

void	do_fractal(t_strct mn, float x, float y)
{
	mlx_clear_window(mn.mlx, mn.win);
	if (mn.fractal == 1)
		mandel(&mn);
	else if (mn.fractal == 2 && x == 0 && y == 0)
	{
		mn.cx = -0.7;
		mn.cy = 0.27015;
		julia(&mn);
	}
	else if (mn.fractal == 2)
	{
		mn.cx = x;
		mn.cy = y;
		julia(&mn);
	}
	else if (mn.fractal == 3)
		tricorn(&mn);
}

void	put_pixels(t_strct *mn, int x, int y)
{
	if (mn->count % 10 < 2)
		mn->pixels[(y * WIDTH) + x] = mn->z.color1;
	else if (mn->count % 10 < 3)
		mn->pixels[(y * WIDTH) + x] = mn->z.color2;
	else if (mn->count % 10 < 4)
		mn->pixels[(y * WIDTH) + x] = mn->z.color3;
	else if (mn->count % 10 < 5)
		mn->pixels[(y * WIDTH) + x] = mn->z.color4;
	else if (mn->count % 10 < 6)
		mn->pixels[(y * WIDTH) + x] = mn->z.color5;
	else if (mn->count % 10 < 7)
		mn->pixels[(y * WIDTH) + x] = mn->z.color6;
	else if (mn->count % 10 < 8)
		mn->pixels[(y * WIDTH) + x] = mn->z.color7;
	else if (mn->count % 10 < 9)
		mn->pixels[(y * WIDTH) + x] = mn->z.color8;
	else if (mn->count % 10 < 10)
		mn->pixels[(y * WIDTH) + x] = mn->z.color9;
}

void	usage(void)
{
	ft_putstr_fd("\nWrong input, either use:\n\n", 1);
	ft_putstr_fd("./fractol 1 for Mandelbrot\n", 1);
	ft_putstr_fd("./fractol 2 [x y] for Julia\n", 1);
	ft_putstr_fd("./fractol 3 for Tricorn\n", 1);
}
