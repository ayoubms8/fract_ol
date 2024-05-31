/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemsafi <alemsafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:58:22 by alemsafi          #+#    #+#             */
/*   Updated: 2023/01/06 16:57:32 by alemsafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# define HEIGHT 550
# define WIDTH 900
# define MAXCNT 50
# define ON_DESTROY 17
# define ESC 53
# define PLUS 24
# define MINUS 27
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123
# define SCROLL_IN 4
# define SCROLL_OUT 5
# define LEFT_CLICK 1
# define COLOR 8

typedef struct s_num
{
	float	real;
	float	img;
	int		color1;
	int		color2;
	int		color3;
	int		color4;
	int		color5;
	int		color6;
	int		color7;
	int		color8;
	int		color9;
}t_num;

typedef struct s_strct
{
	void		*mlx;
	void		*win;
	void		*img;
	float		xscale;
	float		yscale;
	float		xzoom;
	float		yzoom;
	float		left;
	float		top;
	float		leftz;
	float		topz;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	uint32_t	*pixels;
	int			fractal;
	float		cx;
	float		cy;
	int			mod;
	int			count;
	t_num		z;
}t_strct;

int		quit(t_strct *mn);
void	zinit(t_strct *mn);
int		scroll(int key, int x, int y, t_strct *mn);
void	mandel(t_strct *mn);
int		key(int key, t_strct *mn);
void	update(t_strct *mn);
void	put_pixels(t_strct *mn, int x, int y);
void	key2(int key, t_strct *mn);
int		mousemov(int x, int y, t_strct *mn);
void	julia(t_strct *mn);
void	do_fractal(t_strct mn, float x, float y);
void	usage(void);
void	change_color_range(t_strct *mn);
void	assign_colors(t_strct *mn);
void	init_mn(t_strct *mn);
void	loop(t_strct *mn, t_num *z);
void	tricorn(t_strct *mn);
void	triloop(t_strct *mn, t_num *z);
float	ft_atof(char *str);
int		sm_scale(float	*scale);

#endif