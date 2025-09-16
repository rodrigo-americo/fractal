/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:20:05 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 11:13:27 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint(void *n)
{
	unsigned long	addr;
	int				size;

	size = 0;
	addr = (unsigned long)n;
	if (!n)
	{
		size += ft_putstr_fd("(nil)", 1);
		return (size);
	}
	size += ft_putstr_fd("0x", 1);
	size += ft_putul_base(addr, "0123456789abcdef");
	return (size);
}
