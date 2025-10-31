/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:55:53 by rgregori          #+#    #+#             */
/*   Updated: 2025/10/31 18:23:05 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"

void	print_usage(void)
{
	ft_printf("Uso:\n");
	ft_printf("  ./fractol mandelbrot [width height]\n");
	ft_printf("  ./fractol ship [width height]"
		"<min_re> <max_re> <min_im> <min_im>\n");
	ft_printf("  ./fractol julia [width height] <c_re> <c_im> \n");
}

int	main(int argc, char **argv)
{
	t_state	*st;
	t_args	ar;

	if (argc < 2)
	{
		print_usage();
		return (0);
	}
	ft_init_arg(&ar);
	ft_parse_argv(argc, &ar, argv);
	st = ft_init_state(&ar, "fractol");
	if (!st)
		return (1);
	ft_render_frame_parallel(st);
	mlx_put_image_to_window(st->mlx, st->win, st->img, 0, 0);
	mlx_hook(st->win, 2, 1L << 0, ft_key_press, st);
	mlx_hook(st->win, 3, 1L << 1, ft_key_release, st);
	mlx_hook(st->win, 17, 0, ft_on_destroy, st);
	mlx_mouse_hook(st->win, ft_mouse_handler, st);
	mlx_loop_hook(st->mlx, ft_update, st);
	mlx_loop(st->mlx);
}
