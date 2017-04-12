/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:31:25 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/10 04:52:54 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_color(int iteration, t_info *this)
{
	int	max_iterations;
	int	start_color;

	max_iterations = this->fractal->max_iterations;
	start_color = abs(this->fractal->start_color);
	if (iteration == max_iterations)
		return (BLACK);
	return (start_color * iteration * (CONTRAST / MAX_ITERATIONS));
}

static void		put_pixel_on_image(int x, int y, t_info *this)
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	int				color;
	int				bpp;

	color = this->fractal->color;
	bpp = this->mlx->bpp;
	b = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	r = (color & 0xFF);
	this->mlx->data[y * this->mlx->size_line + x * bpp / 8] = r;
	this->mlx->data[y * this->mlx->size_line + x * bpp / 8 + 1] = g;
	this->mlx->data[y * this->mlx->size_line + x * bpp / 8 + 2] = b;
}

int				draw(t_info *this)
{
	double		x;
	double		y;
	t_mlx		*mlx;
	int			*line;

	mlx = this->mlx;
	line = &(this->mlx->size_line);
	mlx->image = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->data = mlx_get_data_addr(mlx->image, &mlx->bpp, line, &mlx->endian);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			this->fractal->color = get_color(get_iteration(x, y, this), this);
			put_pixel_on_image(x, y, this);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->image);
	return (0);
}
