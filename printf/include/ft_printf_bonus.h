/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:51:32 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/26 12:50:21 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	plus;
	int	space;
	int	hash;
	int	width;
	int	precision;
	int	dot;
}	t_flags;

int		ft_printf(const char *format, ...);
/* ************************************************************************** */
/*                              handles                                       */
/* ************************************************************************** */
int		ft_handle_format(const char **format, va_list *args);
void	ft_handle_precision(t_flags *flags, const char **str);
int		ft_handle_char(int c, t_flags *flags);
int		ft_handle_string(char *c, t_flags *flags);
int		ft_handle_signed(int c, t_flags *flags);
int		ft_handle_unsigned(unsigned int c, t_flags *flags);
int		ft_handle_hex(unsigned int c, char type, t_flags *flags);
int		ft_handle_pointer(void *c, t_flags *flags);
int		ft_handle_percent(t_flags *flags);
/* ************************************************************************** */
/*                              utils                                         */
/* ************************************************************************** */
char	*ft_strdup_safe(char *c);
char	*ft_apply_str_precision(char *content, int precision);
char	*ft_apply_int_precision(char *content, int precision);
char	*ft_apply_width(char *content, int width, int left_align);
char	*ft_apply_sign_flag(char *str, t_flags *flags);
char	*ft_apply_flags_hex(char *str, t_flags *flags, int c, char *prefix);
char	*ft_zero_pad(char *str, int width, int is_signed);
char	*ft_zero_pad_prefixed(char *number, char *prefix, int width);
char	*ft_utoa_base(unsigned long n, char *base);
char	*ft_strjoin_free( char *prefix, char *suffix);
/* ************************************************************************** */
/*                              flags                                         */
/* ************************************************************************** */
t_flags	ft_init_flags(void);
void	ft_handle_flags(t_flags *flags, const char **str);
int		ft_is_flag(char c);

/* ************************************************************************** */
/*                              mandatorio                                    */
/* ************************************************************************** */
int		ft_puthex(unsigned long n, char type);
int		ft_putpoint(void *n);
int		ft_putul_base(unsigned long n, char *base);

#endif