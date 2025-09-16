/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:49:52 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 16:34:14 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list			args;
	const char		*next;
	int				size;
	const char		*str;

	va_start(args, format);
	str = (const char *)format;
	size = 0;
	while (*str)
	{
		next = ft_strchr(str, '%');
		if (!next)
		{
			size += ft_putstr_fd(str, 1);
			break ;
		}
		size += write(1, str, next - str);
		str = next;
		size += ft_handle_format(&str, &args);
	}
	return (va_end(args), size);
}
