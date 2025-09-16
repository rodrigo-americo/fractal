/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:37:29 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/05 10:38:51 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"
#include <math.h>

static int	ft_update_max_iter(t_state *st)
{
	static double	span_re_inicial = 0.0;
	static int		iter_base = 150;
	double			factor;

	if (span_re_inicial == 0.0)
		span_re_inicial = st->max_re - st->min_re;
	factor = span_re_inicial / st->vm.span_re;
	st->max_iter = iter_base + 20 * log2(factor);
	if (st->max_iter < iter_base)
		st->max_iter = iter_base;
	return (st->max_iter);
}

static void	zoom(t_state *st, int x, int y, double zoom)
{
	double	new_scale_re;
	double	new_scale_im;
	double	cy;
	double	cx;

	cx = st->min_re + x * st->vm.scale_re;
	cy = st->max_im - y * st->vm.scale_im;
	st->vm.span_re *= zoom;
	st->vm.span_im *= zoom;
	new_scale_re = st->vm.span_re / (st->width - 1);
	st->vm.scale_re = new_scale_re;
	new_scale_im = st->vm.span_im / (st->height - 1);
	st->vm.scale_im = new_scale_im;
	st->min_re = cx - x * new_scale_re;
	st->max_re = st->min_re + st->vm.span_re;
	st->max_im = cy + y * new_scale_im;
	st->min_im = st->max_im - st->vm.span_im;
	ft_update_max_iter(st);
	st->redraw = 1;
}	

int	ft_mouse_handler(int button, int x, int y, void *param)
{
	t_state	*st;

	st = (t_state *)param;
	if (button == 4)
		zoom(st, x, y, st->zoom_factor);
	if (button == 5)
		zoom(st, x, y, 1 / st->zoom_factor);
	return (0);
}
