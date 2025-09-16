/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signed_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:43:20 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/06 13:06:22 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_handle_signed(int c, t_flags *flags)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(c);
	if (!nbr)
		return (0);
	nbr = ft_apply_int_precision(nbr, flags->precision);
	if (c >= 0)
		nbr = ft_apply_sign_flag(nbr, flags);
	if (flags->zero && !flags->minus && flags->precision == -1)
		nbr = ft_zero_pad(nbr, flags->width, 1);
	else
		nbr = ft_apply_width(nbr, flags->width, flags->minus);
	len = ft_putstr_fd(nbr, 1);
	free(nbr);
	return (len);
}
