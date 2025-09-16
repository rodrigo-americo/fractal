/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:11:26 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/01 15:31:54 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"

void	ft_move_up(t_state *st, double dy)
{
	st->min_im += dy;
	st->max_im += dy;
	st->redraw = 1;
	return ;
}

void	ft_move_down(t_state *st, double dy)
{
	st->min_im -= dy;
	st->max_im -= dy;
	st->redraw = 1;
	return ;
}

void	ft_move_right(t_state *st, double dx)
{
	st->min_re += dx;
	st->max_re += dx;
	st->redraw = 1;
	return ;
}

void	ft_move_left(t_state *st, double dx)
{
	st->min_re -= dx;
	st->max_re -= dx;
	st->redraw = 1;
	return ;
}
