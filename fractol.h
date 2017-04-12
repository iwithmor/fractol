/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:29:30 by iwithmor          #+#    #+#             */
/*   Updated: 2017/04/10 04:53:01 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <complex.h>
# include <libc.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WIN_WIDTH		1000
# define WIN_HEIGHT		700

# define ZOOM_FACTOR	1.05
# define MOVE_FACTOR_X	0.01
# define MOVE_FACTOR_Y	0.02
# define CONTRAST		255
# define MAX_ITERATIONS	50

# define MANDELBROT		1
# define JULIA			2
# define OTHER			3

# define ESC			53
# define UP				126
# define DOWN			125
# define RIGHT			124
# define LEFT			123
# define PAGE_UP		116
# define PAGE_DOWN		121

# define PLUS			69
# define MINUS			78

# define BLACK			0x000000
# define PINK			0xFFB6C1
# define LIGHT_BLUE		0x7A5230
# define RED			0x040000

# define LEFT_CLICK		1
# define RIGHT_CLICK	2
# define SCROLL_UP		4
# define SCROLL_DOWN	5

typedef _Complex double	t_complex;

typedef struct			s_pos
{
	double				x;
	double				y;
}						t_pos;

typedef struct			s_fractal
{
	int					type;
	t_pos				*position;
	t_pos				*c;
	double				zoom;
	int					color;
	int					start_color;
	int					max_iterations;
	t_complex			z;
}						t_fractal;

typedef struct			s_mlx
{
	void				*mlx;
	void				*window;
	void				*image;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_mlx;

typedef struct			s_info
{
	t_fractal			*fractal;
	t_mlx				*mlx;
}						t_info;

t_mlx					*new_empty_mlx();
t_fractal				*new_empty_fractal();
t_info					*new_empty_info();
t_pos					*new_empty_position();
t_pos					*new_position(double x, double y);
t_info					*new_info(int fractal_type);
void					new_mandelbrot(t_fractal *fractal);
void					new_julia(t_fractal *fractal);
void					new_other(t_fractal *fractal);
void					start(t_info *this);
void					increase_iterations(t_info *this);
void					decrease_iterations(t_info *this);
int						key_hook(int keycode, t_info *this);
int						mouse_hook(int button, int x, int y, t_info *this);
int						move_mouse(int x, int y, t_info *this);
void					move_up(t_info *this);
void					move_down(t_info *this);
void					move_left(t_info *this);
void					move_right(t_info *this);
void					zoom_in(int x, int y, t_info *this);
void					zoom_out(int x, int y, t_info *this);
int						draw(t_info *this);
int						get_iteration(int x, int y, t_info *this);
void					color_up(t_info *this);
void					color_down(t_info *this);

#endif
