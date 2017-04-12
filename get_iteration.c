/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_iteration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 04:28:46 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/10 04:40:20 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	get_z(double x, double y, t_info *this)
{
	double	z_x;
	double	z_y;
	double	zoom;

	zoom = this->fractal->zoom;
	if (this->fractal->type == MANDELBROT)
		return (0);
	z_x = x / zoom + this->fractal->position->x;
	z_y = y / zoom + this->fractal->position->y;
	if (this->fractal->type == OTHER)
		return (fabs(z_x) + z_y * _Complex_I);
	return (z_x + z_y * _Complex_I);
}

static t_complex	get_c(double x, double y, t_info *this)
{
	double	zoom;
	double	c_x;
	double	c_y;

	zoom = this->fractal->zoom;
	if (this->fractal->type == MANDELBROT)
	{
		c_x = x / zoom + this->fractal->position->x;
		c_y = y / zoom + this->fractal->position->y;
	}
	else
	{
		c_x = this->fractal->c->x;
		c_y = this->fractal->c->y;
	}
	return (c_x + c_y * _Complex_I);
}

static int			within_radius(t_complex z)
{
	return (creal(z) * creal(z) + cimag(z) * cimag(z) < 4);
}

int					get_iteration(int x, int y, t_info *this)
{
	int			i;
	t_complex	c;
	t_complex	z;

	i = 0;
	z = get_z(x, y, this);
	c = get_c(x, y, this);
	while (within_radius(z) && i < this->fractal->max_iterations)
	{
		z = z * z + c;
		i++;
	}
	return (i);
}
