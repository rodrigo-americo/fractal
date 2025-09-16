/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:16:37 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/01 15:14:52 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_H

# define FRAC_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>

# define KEY_ESC     65307
# define MODE_MANDEL 0
# define MODE_JULIA 1

typedef struct s_key_maps
{
	int	esc;
}	t_key_maps;

typedef struct s_vm {
	double	span_re;
	double	span_im;
	double	scale_re;
	double	scale_im;
}	t_vm;

typedef struct s_args
{
	int		mode;
	double	c_re;
	double	c_im;
	int		width;
	int		height;
}	t_args;

typedef struct s_state
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	int			mode;
	double		c_re;
	double		c_im;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		pan_ratio;
	int			redraw;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			max_iter;
	double		escape_sq;
	double		zoom_factor;
	t_key_maps	keys;
	t_vm		vm;
}	t_state;

int		ft_key_press(int keycode, void *param);
int		ft_key_release(int keycode, void *param);
int		ft_update(void *param);
int		ft_on_destroy(void *param);
int		ft_calculate_iters(t_state *st, int x, int y, double *z2);
int		ft_mandel_iters_keepz(double cre, double cim,
			t_state *st, double *out_z2);
int		ft_julia_iters_keepz(double zr0, double zi0,
			t_state *st, double *out_z2);
int		ft_color_from_iter_rgb(int iters, int max_iter);
int		ft_color_from_smooth(int iters, int max_iter, double z2);
void	ft_free_st(t_state *st);
void	ft_free_error(t_state *window, const char *error_message);
void	ft_prepare_vm(t_state *st);
void	ft_render_frame(t_state *st);
void	ft_parse_argv(int ac, t_args *ar, char **av);
int		ft_mouse_handler(int button, int x, int y, void *param);
void	ft_init_arg(t_args *ar);
t_state	*ft_init_state(t_args *ar, char *title);
void	print_usage(void);
#endif 