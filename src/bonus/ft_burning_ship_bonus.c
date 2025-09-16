/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:24:18 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/05 10:39:07 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"
#include <math.h>

static double	ft_mod(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_burning_ship_iters_keepz(double cre, double cim,
		t_state *st, double *out_z2)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		i;

	zr = 0.0;
	zi = 0.0;
	zr2 = 0.0;
	zi2 = 0.0;
	i = 0;
	while (i < st->max_iter && (zr2 + zi2) <= st->escape_sq)
	{
		zr2 = ft_mod(zr);
		zi2 = ft_mod(zi);
		zi = 2.0 * zr2 * zi2 - cim;
		zr = zr2 * zr2 - zi2 * zi2 + cre;
		zr2 = zr * zr;
		zi2 = zi * zi;
		i++;
	}
	*out_z2 = zr2 + zi2;
	return (i);
}
