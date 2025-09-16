/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:35:46 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/01 13:26:41 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

static void	ft_handle_julia_args(int ac, t_args *ar, char **av)
{
	ar->mode = MODE_JULIA;
	if (ac > 2)
	{
		ar->width = ft_atoi(av[2]);
		ar->height = ft_atoi(av[3]);
	}
	if (ac == 6)
	{
		ar->c_re = ft_atod(av[4]);
		ar->c_im = ft_atod(av[5]);
	}
}

void	ft_parse_argv(int ac, t_args *ar, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		ar->mode = MODE_MANDEL;
		if (ac == 4)
		{
			ar->width = ft_atoi(av[2]);
			ar->height = ft_atoi(av[3]);
		}
	}
	else if (ft_strncmp(av[1], "julia", 5) == 0)
		ft_handle_julia_args(ac, ar, av);
	else
	{
		print_usage();
		exit(1);
	}
}
