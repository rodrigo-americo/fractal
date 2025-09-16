/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:01:13 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 17:01:42 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handle_format(const char **format, va_list *args)
{
	t_flags	flags;
	char	type;
	int		size;

	flags = ft_init_flags();
	size = 0;
	ft_handle_flags(&flags, format);
	type = **format;
	if (type == 'c')
		size += ft_handle_char(va_arg(*args, int), &flags);
	else if (type == 's')
		size += ft_handle_string(va_arg(*args, char *), &flags);
	else if (type == 'd' || type == 'i')
		size += ft_handle_signed(va_arg(*args, int), &flags);
	else if (type == 'u')
		size += ft_handle_unsigned(va_arg(*args, unsigned int), &flags);
	else if (type == 'x' || type == 'X')
		size += ft_handle_hex(va_arg(*args, unsigned int), type, &flags);
	else if (type == 'p')
		size += ft_handle_pointer(va_arg(*args, void *), &flags);
	else if (type == '%')
		size += ft_handle_percent(&flags);
	(*format)++;
	return (size);
}
