/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 00:05:34 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/10 04:52:53 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_up(t_info *this)
{
	void	*mlx;
	void	*window;
	double	zoom;

	mlx = this->mlx->mlx;
	window = this->mlx->window;
	zoom = this->fractal->zoom;
	mlx_clear_window(mlx, window);
	this->fractal->position->y -= 0.1 * WIN_HEIGHT / zoom / 2;
	draw(this);
}

void	move_down(t_info *this)
{
	void	*mlx;
	void	*window;
	double	zoom;

	mlx = this->mlx->mlx;
	window = this->mlx->window;
	zoom = this->fractal->zoom;
	mlx_clear_window(mlx, window);
	this->fractal->position->y += 0.1 * WIN_HEIGHT / zoom / 2;
	draw(this);
}

void	move_left(t_info *this)
{
	void	*mlx;
	void	*window;
	double	zoom;

	mlx = this->mlx->mlx;
	window = this->mlx->window;
	zoom = this->fractal->zoom;
	mlx_clear_window(mlx, window);
	this->fractal->position->x -= 0.1 * WIN_WIDTH / zoom / 2;
	draw(this);
}

void	move_right(t_info *this)
{
	void	*mlx;
	void	*window;
	double	zoom;

	mlx = this->mlx->mlx;
	window = this->mlx->window;
	zoom = this->fractal->zoom;
	mlx_clear_window(mlx, window);
	this->fractal->position->x += 0.1 * WIN_WIDTH / zoom / 2;
	draw(this);
}
