/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:35:46 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/02 15:00:22 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"

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

static void	ft_handle_ship(int ac, t_args *ar, char **av)
{
	ar->mode = MODE_SHIP;
	if (ac == 4)
	{
		ar->width = ft_atoi(av[2]);
		ar->height = ft_atoi(av[3]);
	}
	ar->min_re = -2.0;
	ar->max_re = 1.0;
	ar->min_im = -1.2;
	ar->max_im = 1.2;
	if (ac == 8)
	{
		ar->min_re = ft_atod(av[4]);
		ar->max_re = ft_atod(av[5]);
		ar->min_im = ft_atod(av[6]);
		ar->max_im = ft_atod(av[7]);
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
	else if (ft_strncmp(av[1], "ship", 4) == 0)
		ft_handle_ship(ac, ar, av);
	else
	{
		print_usage();
		exit(1);
	}
	if (ar->width <= 0 || ar->height <= 0
		|| ar->height > 4000 || ar->width > 4000)
	{
		ft_printf("Dimensões inválidas; usando 1080x900 por padrão.\n");
		ar->width = 1080;
		ar->height = 900;
	}
}
