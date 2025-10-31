/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:21:19 by rgregori          #+#    #+#             */
/*   Updated: 2025/10/31 18:30:46 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frac_bonus.h"

static void populate_tile(t_state *st, t_work_queue *queue)
{
	int		x;
	int		y;
	int		i;
	t_tile	*tile;

	y = 0;
	i = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			tile = &queue->tiles[i];
			tile->start_x = x;
			tile->start_y = y;
			tile->end_x = fmin(x + st->tile_size, st->width);
			tile->end_y = fmin(y + st->tile_size, st->height);
			i++;
			x += st->tile_size;
		}
		y += st->tile_size;
	}
}

t_work_queue *ft_create_work_queue(t_state *st)
{
	t_work_queue	*queue;
	int				tile_x;
	int				tile_y;

	tile_x = ceil((double)st->width / st->tile_size);
	tile_y = ceil((double)st->height / st->tile_size);
	queue = malloc(sizeof(t_work_queue));
	if (!queue)
	return (NULL);
	queue->num_tiles = tile_x * tile_y;
    queue->tiles = malloc(sizeof(t_tile) * queue->num_tiles);
	if (!queue->tiles)
	{
		free(queue);
		return (NULL);
	}
	queue->next_tile = 0;
	populate_tile(st, queue);
	pthread_mutex_init(&queue->work_mutex, NULL);
	return (queue);
}

void	ft_render_frame(t_state *st)
{
	int		x;
	int		y;
	int		iters;
	double	z2;

	ft_prepare_vm(st);
	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			iters = ft_calculate_iters(st, x, y, &z2);
			ft_put_pixel(st, x, y,
				ft_color_from_smooth(iters, st->max_iter, z2, st->palette_id));
			x++;
		}
		y++;
	}
	st->redraw = 0;
}

void render_tile(t_state *st, t_tile *tile)
{
    int		x;
	int		y;
	int		iters;
	double	z2;

	y = tile->start_y;
	while (y < tile->end_y)
	{
		x = tile->start_x;
		while (x < tile->end_x)
		{
			iters = ft_calculate_iters(st, x, y, &z2);
			ft_put_pixel(st, x, y,
				ft_color_from_smooth(iters, st->max_iter, z2, st->palette_id));
			x++;
		}
		y++;
	}

}

void *ft_worker_thread(void *arg)
{
    t_thread_data *data;
    int my_tile_index;
	
	data = (t_thread_data *)arg;
    while (1)
    {
		pthread_mutex_lock(&data->queue->work_mutex);
		if (data->queue->next_tile >= data->queue->num_tiles)
		{
			pthread_mutex_unlock(&data->queue->work_mutex);
			break ;
		}
		my_tile_index = data->queue->next_tile;
		data->queue->next_tile++;	
		pthread_mutex_unlock(&data->queue->work_mutex);
        render_tile(data->st, &data->queue->tiles[my_tile_index]);
    }
	return (NULL);
}

void ft_render_frame_parallel(t_state *st)
{
    pthread_t threads[20];
    t_thread_data data[20];
    t_work_queue *queue;
    int i;
    int created;  // ← contador de threads criadas com sucesso
    
    ft_prepare_vm(st);
    queue = ft_create_work_queue(st);
    if (!queue)
        return;
    
    i = 0;
    created = 0;
    while (i < 20)
    {
        data[i].st = st;
        data[i].queue = queue;
        
        if (pthread_create(&threads[i], NULL, 
                          ft_worker_thread, &data[i]) != 0)
        {
            // Falhou - precisamos limpar
            break;  // para de criar threads
        }
        created++;  // mais uma thread criada com sucame(st);esso
        i++;
    }
    i = 0;
    while (i < created)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
    pthread_mutex_destroy(&queue->work_mutex);  // ← UMA vez só!
    free(queue->tiles);
    free(queue);
    st->redraw = 0;
}
