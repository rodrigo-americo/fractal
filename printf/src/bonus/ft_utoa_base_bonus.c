/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:37:11 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 14:19:34 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_count_digits(unsigned long n, int base_len)
{
	int	count;

	count = 1;
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		count++;
	}
	return (count);
}

char	*ft_utoa_base(unsigned long n, char *base)
{
	char	*res;
	int		size;
	int		base_len;

	base_len = ft_strlen(base);
	if (!base || base_len < 2)
		return (NULL);
	size = ft_count_digits(n, base_len);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (size--)
	{
		res[size] = base[n % base_len];
		n /= base_len;
	}
	return (res);
}
