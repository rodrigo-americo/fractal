/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:16:37 by rgregori          #+#    #+#             */
/*   Updated: 2025/10/31 18:31:31 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAC_BONUS_H

# define FRAC_BONUS_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <pthread.h>
# include <stdlib.h>
# include <math.h>

# define KEY_ESC     65307
# define KEY_LEFT    65361
# define KEY_UP      65362
# define KEY_RIGHT   65363
# define KEY_DOWN    65364
# define KEY_SPACE 32
# define MODE_MANDEL 0
# define MODE_JULIA 1
# define MODE_SHIP 2
# define N_PALETTES 3

typedef struct s_key_maps
{
	int	esc;
	int	up;
	int	down;
	int	left;
	int	right;
	int	space;
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
	double	min_re;
	double	max_re;
	double	min_im;
	double	max_im;
}	t_args;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

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
	int			palette_id;
	double		escape_sq;
	double		zoom_factor;
	int			tile_size;
	t_key_maps	keys;
	t_vm		vm;
}	t_state;

typedef struct s_tile
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
} t_tile;

typedef struct s_work_queue{
	
	t_tile	*tiles;
	int		num_tiles;
	int		next_tile;
	pthread_mutex_t	work_mutex;
} t_work_queue;

typedef struct s_thread_data
{
	t_state			*st;
	t_work_queue	*queue;
}	t_thread_data;

int		ft_key_press(int keycode, void *param);
int		ft_key_release(int keycode, void *param);
int		ft_update(void *param);
int		ft_on_destroy(void *param);
int		ft_calculate_iters(t_state *st, int x, int y, double *z2);
int		ft_mandel_iters_keepz(double cre, double cim,
			t_state *st, double *out_z2);
int		ft_julia_iters_keepz(double zr0, double zi0,
			t_state *st, double *out_z2);
int		ft_burning_ship_iters_keepz(double cre, double cim,
			t_state *st, double *out_z2);
int		ft_color_from_iter_rgb(int iters, int max_iter);
int		ft_color_from_smooth(int iters, int max_iter,
			double z2, int palette_id);
void	ft_free_st(t_state *st);
void	ft_free_error(t_state *window, const char *error_message);
void	ft_move_up(t_state *st, double dy);
void	ft_move_down(t_state *st, double dy);
void	ft_move_right(t_state *st, double dx);
void	ft_move_left(t_state *st, double dx);
void	ft_prepare_vm(t_state *st);
void	ft_render_frame(t_state *st);
void	ft_parse_argv(int ac, t_args *ar, char **av);
int		ft_mouse_handler(int button, int x, int y, void *param);
void	ft_handle_move(t_state *st, double dx, double dy);
void	ft_init_arg(t_args *ar);
t_state	*ft_init_state(t_args *ar, char *title);
void	ft_put_pixel(t_state *st, int x, int y, int color);
void	print_usage(void);
t_work_queue *ft_create_work_queue(t_state *st);
void render_tile(t_state *st, t_tile *tile);
void ft_render_frame_parallel(t_state *st);
void *ft_worker_thread(void *arg);
#endif 