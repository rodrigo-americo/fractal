/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:08:24 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/01 15:31:46 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"
#include <math.h>

int	ft_julia_iters_keepz(double zr0, double zi0, t_state *st, double *out_z2)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		i;

	zr = zr0;
	zi = zi0;
	zr2 = zr * zr;
	zi2 = zi * zi;
	i = 0;
	while (i < st->max_iter && (zr2 + zi2) <= st->escape_sq)
	{
		zi = 2.0 * zr * zi + st->c_im;
		zr = zr2 - zi2 + st->c_re;
		zr2 = zr * zr;
		zi2 = zi * zi;
		i++;
	}
	*out_z2 = zr2 + zi2;
	return (i);
}
