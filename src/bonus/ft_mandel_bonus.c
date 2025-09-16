/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandel_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:19:50 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/01 15:31:50 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"
#include <math.h>

int	ft_mandel_iters_keepz(double cre, double cim, t_state *st, double *out_z2)
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
		zi = 2.0 * zr * zi + cim;
		zr = zr2 - zi2 + cre;
		zr2 = zr * zr;
		zi2 = zi * zi;
		i++;
	}
	*out_z2 = zr2 + zi2;
	return (i);
}
