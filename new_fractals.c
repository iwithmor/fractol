/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fractals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 04:44:09 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/10 04:46:07 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_mandelbrot(t_fractal *fractal)
{
	fractal->type = MANDELBROT;
	fractal->position = new_position(-2.6, -1.2);
	fractal->zoom = 300;
	fractal->start_color = RED;
	fractal->max_iterations = MAX_ITERATIONS;
}

void	new_julia(t_fractal *fractal)
{
	fractal->type = JULIA;
	fractal->position = new_position(-2.8, -1.9);
	fractal->zoom = 175;
	fractal->start_color = LIGHT_BLUE;
	fractal->max_iterations = MAX_ITERATIONS;
	fractal->c = new_position(0, 0);
}

void	new_other(t_fractal *fractal)
{
	fractal->type = OTHER;
	fractal->position = new_position(-2.8, -1.9);
	fractal->zoom = 175;
	fractal->start_color = PINK;
	fractal->max_iterations = MAX_ITERATIONS;
	fractal->c = new_position(0, 0);
}
