/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:01:08 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/01 15:31:31 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"
#include "ft_printf.h"

void	ft_free_st(t_state *st)
{
	if (!st)
		return ;
	if (st->img)
		mlx_destroy_image(st->mlx, st->img);
	if (st->win)
		mlx_destroy_window(st->mlx, st->win);
	if (st->mlx)
	{
		mlx_destroy_display(st->mlx);
		free(st->mlx);
	}
	free(st);
	exit(0);
}

void	ft_free_error(t_state *st, const char *error_message)
{
	ft_free_st(st);
	if (error_message)
		ft_printf("Error: %s\n", error_message);
}
