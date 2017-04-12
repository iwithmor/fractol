/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <iwithmor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:27:22 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/19 03:50:19 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_fractal_type(char *type)
{
	if (ft_strequ(type, "1"))
		return (1);
	else if (ft_strequ(type, "2"))
		return (2);
	else if (ft_strequ(type, "3"))
		return (3);
	ft_putstr("Invalid fractal:\n(1) mandelbrot\n(2) julia\n(3) other\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	int			type;
	t_info		*this;

	if (argc != 2)
	{
		ft_putstr("usage:	./fractol [fractal_number]\n");
		return (0);
	}
	type = get_fractal_type(argv[1]);
	this = new_info(type);
	start(this);
	return (0);
}
