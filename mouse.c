/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:06:40 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/10 04:55:39 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_info *this)
{
	if (button == LEFT_CLICK)
		increase_iterations(this);
	else if (button == RIGHT_CLICK)
		decrease_iterations(this);
	else if (button == SCROLL_UP)
		zoom_in(x, y, this);
	else if (button == SCROLL_DOWN)
		zoom_out(x, y, this);
	return (0);
}

int	move_mouse(int x, int y, t_info *this)
{
	static int	center_x = WIN_WIDTH / 2;
	static int	center_y = WIN_HEIGHT / 2;

	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		if (x != center_x)
			this->fractal->c->x += MOVE_FACTOR_X * (x - center_x);
		if (y != center_y)
			this->fractal->c->y += MOVE_FACTOR_Y * (y - center_y);
		center_x = x;
		center_y = y;
		mlx_clear_window(this->mlx->mlx, this->mlx->window);
		draw(this);
	}
	return (0);
}
