/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_smooth.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:54:39 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/01 15:41:46 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac.h"
#include <math.h>

static int	ft_arround_color(int color)
{
	if (color < 0)
		return (0);
	if (color > 255)
		return (255);
	return (color);
}

int	ft_color_from_smooth(int iters, int max_iter, double z2)
{
	double	nu;
	double	t;
	int		r;
	int		g;
	int		b;

	if (iters >= max_iter)
		return (0x000000);
	nu = iters + 1.0 - log2(log(sqrt(z2)));
	t = nu / (double)max_iter;
	if (t < 0.0)
		t = 0.0;
	if (t > 1.0)
		t = 1.0;
	r = (int)(9.0 * (1 - t) * t * t * t * 255.0);
	g = (int)(15.0 * (1 - t) * (1 - t) * t * t * 255.0);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255.0);
	r = ft_arround_color(r);
	g = ft_arround_color(g);
	b = ft_arround_color(b);
	return ((r << 16) | (g << 8) | b);
}
