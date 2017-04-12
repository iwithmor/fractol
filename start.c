/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:06:40 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/10 04:55:39 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		start(t_info *this)
{
	int		type;
	void	*mlx;
	void	*window;

	type = this->fractal->type;
	mlx = this->mlx->mlx;
	window = this->mlx->window;
	mlx_expose_hook(window, draw, this);
	mlx_mouse_hook(window, mouse_hook, this);
	mlx_key_hook(window, key_hook, this);
	if (type != MANDELBROT)
		mlx_hook(window, 6, (1L << 6), move_mouse, this);
	mlx_loop(mlx);
}
