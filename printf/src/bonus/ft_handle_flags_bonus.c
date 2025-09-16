/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:27:04 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 17:01:03 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_handle_flags(t_flags *flags, const char **str)
{
	char	flag;

	(*str)++;
	while (ft_is_flag(**str))
	{
		flag = **str;
		if (flag == '-')
			flags->minus = 1;
		else if (flag == '0')
			flags->zero = 1;
		else if (flag == '#')
			flags->hash = 1;
		else if (flag == ' ')
			flags->space = 1;
		else if (flag == '+')
			flags->plus = 1;
		(*str)++;
	}
	if (ft_isdigit(**str) && **str != '0')
	{
		flags->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	ft_handle_precision(flags, str);
}
