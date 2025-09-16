/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:49:29 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 11:42:56 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.hash = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.dot = 0;
	return (flags);
}
