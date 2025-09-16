/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:04:16 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 11:22:47 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putul_base(unsigned long n, char *base)
{
	int		size;
	int		size_base;

	size = 0;
	size_base = ft_strlen(base);
	if (n >= (unsigned long)size_base)
		size += ft_putul_base(n / size_base, base);
	size += ft_putchar_fd(base[n % size_base], 1);
	return (size);
}
