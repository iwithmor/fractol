/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enhance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 04:13:49 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/17 04:52:08 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	increase_iterations(t_info *this)
{
	void	*mlx;
	void	*window;

	mlx = this->mlx->mlx;
	window = this->mlx->window;
	mlx_clear_window(mlx, window);
	this->fractal->max_iterations += 1;
	draw(this);
}

void	decrease_iterations(t_info *this)
{
	void	*mlx;
	void	*window;

	mlx = this->mlx->mlx;
	window = this->mlx->window;
	mlx_clear_window(mlx, window);
	this->fractal->max_iterations -= 1;
	draw(this);
}
