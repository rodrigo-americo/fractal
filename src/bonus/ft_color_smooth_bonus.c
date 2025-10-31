/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_smooth_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:54:39 by rgregori          #+#    #+#             */
/*   Updated: 2025/10/31 18:42:43 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"
#include <math.h>

static int	ft_arround_color(int color)
{
	if (color < 0)
		return (0);
	if (color > 255)
		return (255);
	return (color);
}

static void	ft_arround_rgb(t_color *color)
{
	color->r = ft_arround_color(color->r);
	color->g = ft_arround_color(color->g);
	color->b = ft_arround_color(color->b);
}

static void	ft_handle_palette(double t, int palette_id, t_color *color)
{
	if (palette_id == 0)
	{
		color->r = (int)(9.0 * (1 - t) * t * t * t * 255.0);
		color->g = (int)(15.0 * (1 - t) * (1 - t) * t * t * 255.0);
		color->b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255.0);
	}
	else if (palette_id == 1)
	{
		color->r = (int)(t * 50);
		color->g = (int)(t * 200);
		color->b = (int)(t * 255);
	}
	else
	{
		color->r = (int)(t * 255);
		color->g = color->r;
		color->b = color->r;
	}
}

int	ft_color_from_smooth(int iters, int max_iter, double z2, int palette_id)
{
	double	nu;
	double	t;
	t_color	color;

	if (iters >= max_iter)
		return (0x000000);
	nu = iters + 1.0 - log2(log(sqrt(z2)));
	t = log(nu + 1) / log(max_iter + 1);
	if (t < 0.0)
		t = 0.0;
	if (t > 1.0)
		t = 1.0;
	ft_handle_palette(t, palette_id, &color);
	ft_arround_rgb(&color);
	return ((color.r << 16) | (color.g << 8) | color.b);
}
