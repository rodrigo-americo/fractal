/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_iters_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:51:48 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/01 13:54:30 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"

int	ft_calculate_iters(t_state *st, int x, int y, double *z2)
{
	int		inters;
	double	re;
	double	im;

	re = st->min_re + x * st->vm.scale_re;
	im = st->max_im - y * st->vm.scale_im;
	if (st->mode == MODE_MANDEL)
		inters = ft_mandel_iters_keepz(re, im, st, z2);
	else if (st->mode == MODE_JULIA)
		inters = ft_julia_iters_keepz(re, im, st, z2);
	else
		inters = ft_burning_ship_iters_keepz(re, im, st, z2);
	return (inters);
}
