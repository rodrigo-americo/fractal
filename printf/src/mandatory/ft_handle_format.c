/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:01:13 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 11:03:13 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(const char *str, va_list *args)
{
	const char	type = *str;
	int			size;

	size = 0;
	if (type == 'c')
		size += ft_putchar_fd(va_arg(*args, int), 1);
	else if (type == 's')
		size += ft_handle_string(va_arg(*args, const char *));
	else if (type == 'd' || type == 'i')
		size += ft_putnbr_fd(va_arg(*args, int), 1);
	else if (type == 'u')
		size += ft_putul_base(va_arg(*args, unsigned int), "0123456789");
	else if (type == 'x' || type == 'X')
		size += ft_puthex(va_arg(*args, unsigned int), type);
	else if (type == 'p')
		size += ft_putpoint(va_arg(*args, void *));
	else if (type == '%')
		size += ft_putchar_fd('%', 1);
	return (size);
}
