/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:59:06 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 11:06:21 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_string(const char *str)
{
	if (!str)
	{
		return (ft_putstr_fd("(null)", 1));
	}
	return (ft_putstr_fd(str, 1));
}
