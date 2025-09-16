/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_precission_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:28:02 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/08 14:41:40 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_handle_precision(t_flags *flags, const char **str)
{
	if (**str == '.')
	{
		flags->dot = 1;
		(*str)++;
		if (ft_isdigit(**str))
		{
			flags->precision = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
		else
			flags->precision = 0;
	}
}
