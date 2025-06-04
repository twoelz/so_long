/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:26:01 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/04 02:00:25 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_long_bonus(t_game_data *g)
{
	record_item_positions(g);
	put_str_bonus(g, "hello world");
	put_str_bonus(g, "hello world");
}

int	init_game_data_bonus(t_game_data *g)
{
	g->bonus.remove_collect_time = ft_calloc(g->item.total_collect + 1,
			sizeof(double));
	if (!g->bonus.remove_collect_time)
		return (set_error_code(g, E_ALLOC));
	g->bonus.remove_collect_time[g->item.total_collect] = -1;
	g->bonus.collect_point = ft_calloc(g->item.total_collect + 1,
			sizeof(t_point));
	if (!g->bonus.remove_collect_time)
		return (set_error_code(g, E_ALLOC));
	g->bonus.collect_point[g->item.total_collect].x = -1;
	g->bonus.collect_point[g->item.total_collect].y = -1;
	g->bonus.remove_exit = false;
	clear_buf_bonus(g);
	return (E_SUCCESS);
}

void	clear_buf_bonus(t_game_data *g)
{
	ft_bzero(g->bonus.buf, BONUS_BUFFER_SIZE);
	g->bonus.buf_end = 0;
}

void	record_item_positions(t_game_data *g)
{
	size_t	i;

	i = 0;
	while (i < g->item.total_collect)
	{
		g->bonus.collect_point[i].x = g->tile.collect[i]->instances[0].x;
		g->bonus.collect_point[i].y = g->tile.collect[i]->instances[0].y;
		i++;
	}
	g->bonus.exit_point.x = g->tile.exit_open->instances[0].x;
	g->bonus.exit_point.y = g->tile.exit_open->instances[0].y;
}

void	add_to_buf_bonus(t_game_data *g, char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	if ((len + g->bonus.buf_end + 1) > BONUS_BUFFER_SIZE)
		return (clear_buf_bonus(g));
	i = 0;
	while (i < len)
	{
		g->bonus.buf[i + g->bonus.buf_end] = str[i];
		i++;
	}
	g->bonus.buf_end += len;
}

void	print_buf_bonus(t_game_data *g)
{
	put_str_bonus(g, g->bonus.buf);
	clear_buf_bonus(g);
}

void	put_str_bonus(t_game_data *g, char *string)
{
	if (g->bonus.text_image)
		mlx_delete_image(g->mlx, g->bonus.text_image);
	g->bonus.text_image = mlx_put_string(g->mlx, string, 10, 10);
	if (!g->bonus.text_image)
		exit_mlx_error(g, true);
}
