/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:06:40 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/10 04:55:39 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_info *this)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == UP)
		move_up(this);
	else if (keycode == DOWN)
		move_down(this);
	else if (keycode == LEFT)
		move_left(this);
	else if (keycode == RIGHT)
		move_right(this);
	else if (keycode == PLUS)
		color_up(this);
	else if (keycode == MINUS)
		color_down(this);
	return (0);
}
