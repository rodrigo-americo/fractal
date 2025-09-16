/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:51:32 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/26 12:49:00 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_handle_format(const char *str, va_list *args);
int	ft_handle_string(const char *str);
int	ft_puthex(unsigned long n, char type);
int	ft_putpoint(void *n);
int	ft_putul_base(unsigned long n, char *base);

#endif