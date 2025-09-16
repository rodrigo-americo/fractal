/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:14:47 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/04 16:59:23 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char type)
{
	int		size;

	size = 0;
	if (type == 'x')
		size += ft_putul_base(n, "0123456789abcdef");
	else
		size += ft_putul_base(n, "0123456789ABCDEF");
	return (size);
}
