/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_eventos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:28:23 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/01 11:37:21 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include "ft_printf.h"

int	ft_key_press(int keycode, void *param)
{
	t_state	*st;

	st = (t_state *)param;
	if (keycode == KEY_ESC)
		st->keys.esc = 1;
	return (0);
}

int	ft_key_release(int keycode, void *param)
{
	t_state	*st;

	st = (t_state *)param;
	if (keycode == KEY_ESC)
		st->keys.esc = 0;
	return (0);
}

int	ft_update(void *param)
{
	t_state	*st;
	double	dx;
	double	dy;

	st = (t_state *)param;
	dx = st->pan_ratio * (st->max_re - st->min_re);
	dy = st->pan_ratio * (st->max_im - st->min_im);
	if (st->keys.esc)
	{
		ft_free_st(st);
		return (0);
	}
	if (st->redraw)
	{
		ft_render_frame(st);
		mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
		st->redraw = 0;
	}
	return (0);
}

int	ft_on_destroy(void *param)
{
	t_state	*st;

	st = (t_state *)param;
	ft_free_st(st);
	return (0);
}
