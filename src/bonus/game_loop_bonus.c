/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:56:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/02 02:30:35 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	loop_remove_collect(t_game_data *g)
{
	size_t	i;
	bool	removed;
	int		size;
	double	elapsed;

	i = 0;
	removed = true;
	while (i < g->item.total_collect)
	{
		if (g->tile.collect[i]->instances[0].z == Z_REMOVE)
		{
			removed = false;
			elapsed = mlx_get_time() - g->bonus.remove_collect_time[i];
			size = g->tilesiz;
			if (elapsed < 0.5)
			{
				size = (0.5 - elapsed) * size;
				if (size < 9)
					size = 9;
			}
			if (elapsed >= 0.5)
			{
				g->tile.collect[i]->instances[0].enabled = false;
				mlx_set_instance_depth(&g->tile.collect[i]->instances[0], \
					Z_COLLECTIBLE);
			}
			mlx_resize_image(g->tile.collect[i], size, size);
		}
		i++;
	}
	if (removed)
		g->bonus.remove_collect = false;
}

void	game_loop_bonus(void *param)
{
	t_game_data	*g;

	g = (t_game_data *)param;
	if (g->bonus.remove_collect)
		loop_remove_collect(g);
}

