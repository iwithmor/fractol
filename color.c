/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 04:13:49 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/17 04:52:08 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_up(t_info *this)
{
	void	*mlx;
	void	*window;

	mlx = this->mlx->mlx;
	window = this->mlx->window;
	mlx_clear_window(mlx, window);
	this->fractal->start_color += 1;
	draw(this);
}

void	color_down(t_info *this)
{
	void	*mlx;
	void	*window;

	mlx = this->mlx->mlx;
	window = this->mlx->window;
	mlx_clear_window(mlx, window);
	this->fractal->start_color -= 1;
	draw(this);
}
