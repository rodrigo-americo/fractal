/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_eventos_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:28:23 by rgregori          #+#    #+#             */
/*   Updated: 2025/10/31 18:23:22 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"

int	ft_key_press(int keycode, void *param)
{
	t_state	*st;

	st = (t_state *)param;
	if (keycode == KEY_ESC)
		st->keys.esc = 1;
	else if (keycode == KEY_UP)
		st->keys.up = 1;
	else if (keycode == KEY_DOWN)
		st->keys.down = 1;
	else if (keycode == KEY_LEFT)
		st->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		st->keys.right = 1;
	return (0);
}

int	ft_key_release(int keycode, void *param)
{
	t_state	*st;

	st = (t_state *)param;
	if (keycode == KEY_ESC)
		st->keys.esc = 0;
	else if (keycode == KEY_UP)
		st->keys.up = 0;
	else if (keycode == KEY_DOWN)
		st->keys.down = 0;
	else if (keycode == KEY_LEFT)
		st->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		st->keys.right = 0;
	if (keycode == KEY_SPACE)
	{
		st->palette_id = (st->palette_id + 1) % N_PALETTES;
		st->redraw = 1;
	}
	return (0);
}

void	ft_handle_move(t_state *st, double dx, double dy)
{
	if (st->keys.up)
		ft_move_up(st, dy);
	if (st->keys.left)
		ft_move_left(st, dx);
	if (st->keys.down)
		ft_move_down(st, dy);
	if (st->keys.right)
		ft_move_right(st, dx);
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
	ft_handle_move(st, dx, dy);
	if (st->redraw)
	{
		ft_render_frame_parallel(st);
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
