/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:56:26 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/10 04:52:54 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pos		*new_position(double x, double y)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (!new)
	{
		ft_putstr("Insufficient memory\n");
		exit(0);
	}
	new->x = x;
	new->y = y;
	return (new);
}

t_fractal	*new_fractal(int fractal_type)
{
	t_fractal *f;

	f = (t_fractal *)malloc(sizeof(t_fractal));
	if (!f)
	{
		ft_putstr("Insufficient memory\n");
		exit(0);
	}
	if (fractal_type == MANDELBROT)
		new_mandelbrot(f);
	else if (fractal_type == JULIA)
		new_julia(f);
	else if (fractal_type == OTHER)
		new_other(f);
	return (f);
}

t_mlx		*new_mlx(void)
{
	t_mlx	*new;

	new = (t_mlx *)malloc(sizeof(t_mlx));
	if (!new)
	{
		ft_putstr("Insufficient memory\n");
		exit(0);
	}
	new->mlx = mlx_init();
	new->window = mlx_new_window(new->mlx, WIN_WIDTH, WIN_HEIGHT, "FRACTALS");
	return (new);
}

t_info		*new_info(int fractal_type)
{
	t_info		*this;

	this = (t_info *)malloc(sizeof(t_info));
	if (!this)
	{
		ft_putstr("Insufficient memory\n");
		exit(0);
	}
	this->fractal = new_fractal(fractal_type);
	this->mlx = new_mlx();
	return (this);
}
