/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:49:52 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 16:25:51 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		str = next + 1;
		size += ft_handle_format(str, &args);
		str++;
	}
	va_end(args);
	return (size);
}
