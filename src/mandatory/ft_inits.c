/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:22:26 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/29 13:35:10 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"

void	ft_init_vals(t_state *st, t_args *ar)
{
	st->width = ar->width;
	st->height = ar->height;
	st->min_re = -2.0;
	st->max_re = 1.0;
	st->min_im = -1.2;
	st->max_im = 1.2;
	st->c_im = ar->c_im;
	st->c_re = ar->c_re;
	st->mode = ar->mode;
	st->pan_ratio = 0.05;
	st->redraw = 1;
	st->zoom_factor = 0.9;
	st->max_iter = 150;
	st->escape_sq = 4.0;
	st->keys = (t_key_maps){0};
}

int	ft_handle_start_img(t_state *st)
{
	st->img = mlx_new_image(st->mlx, st->width, st->height);
	if (!st->img)
	{
		ft_free_error(st, "Failed to initialize img");
		return (0);
	}
	st->addr = mlx_get_data_addr(st->img, &st->bpp, &st->line_len, &st->endian);
	if (!st->addr)
	{
		ft_free_error(st, "Failed to initialize addr");
		return (0);
	}
	return (1);
}

t_state	*ft_init_state(t_args *ar, char *title)
{
	t_state	*st;

	st = malloc(sizeof(t_state));
	if (!st)
		return (NULL);
	ft_init_vals(st, ar);
	st->mlx = mlx_init();
	if (!st->mlx)
	{
		ft_free_error(st, "Failed to initialize mlx");
		return (NULL);
	}
	st->win = mlx_new_window(st->mlx, st->width, st->height, title);
	if (!st->win)
	{
		ft_free_error(st, "Failed to initialize win");
		return (NULL);
	}
	if (ft_handle_start_img(st) == 0)
		return (NULL);
	return (st);
}

void	ft_init_arg(t_args *ar)
{
	ar->mode = MODE_MANDEL;
	ar->c_re = -0.8;
	ar->c_im = 0.156;
	ar->width = 800;
	ar->height = 600;
}
