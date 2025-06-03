/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:23:47 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/03 00:32:14 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_cleanup(t_game_data *g)
{
	ft_putendl("before closing window");
	mlx_close_window(g->mlx);
	ft_putendl("after closing window");
	if (g->tile.initialized)
		my_tiles_cleanup(g);
	ft_putendl("before terminate");
	mlx_terminate(g->mlx);
}

void	my_tiles_cleanup(t_game_data *g)
{
	t_tiles	*tile;
	size_t	i;
	ft_putendl("will start tile cleanup");
	tile = &g->tile;
	mlx_delete_image(g->mlx, tile->exit_closed);
	mlx_delete_image(g->mlx, tile->exit_open);
	mlx_delete_image(g->mlx, tile->player_down_left);
	mlx_delete_image(g->mlx, tile->player_down_right);
	mlx_delete_image(g->mlx, tile->player_left);
	mlx_delete_image(g->mlx, tile->player_right);
	mlx_delete_image(g->mlx, tile->space);
	mlx_delete_image(g->mlx, tile->wall);
	ft_putendl("tiles cleaned except tile colects");
	i = 0;
	while (i < g->item.total_collect)
	{
		mlx_delete_image(g->mlx, tile->collect[i]);
		i++;
	}
}
