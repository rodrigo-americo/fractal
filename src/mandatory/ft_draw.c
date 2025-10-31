/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:16:51 by rgregori          #+#    #+#             */
/*   Updated: 2025/10/31 18:32:42 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include <math.h>

void	ft_put_pixel(t_state *st, int x, int y, int color)
{
	char	*dst;

	if (st->bpp != 32)
		return ;
	if (x < 0 || x >= st->width || y < 0 || y >= st->height)
		return ;
	dst = st->addr + (y * st->line_len + x * (st->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_prepare_vm(t_state *st)
{
	st->vm.span_re = st->max_re - st->min_re;
	st->vm.span_im = st->max_im - st->min_im;
	st->vm.scale_re = st->vm.span_re / (st->width - 1);
	st->vm.scale_im = st->vm.span_im / (st->height - 1);
}

void	ft_render_frame(t_state *st)
{
	int		x;
	int		y;
	int		iters;
	double	z2;

	ft_prepare_vm(st);
	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			iters = ft_calculate_iters(st, x, y, &z2);
			ft_put_pixel(st, x, y,
				ft_color_from_smooth(iters, st->max_iter, z2));
			x++;
		}
		y++;
	}
	st->redraw = 0;
}
