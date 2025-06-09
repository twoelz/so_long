/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_position_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:24:51 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/08 21:57:31 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	process_position_bonus(t_game_data *g)
{
	t_bonus	*b;

	b = (t_bonus *)g->bonus;

	if (player_hit_enemy(g, b))
		game_lost(g, b);
	else
	{
		add_to_buf_bonus(b, ft_itoa(g->moves));
		add_to_buf_bonus(b, " moves");
		print_buf_bonus(g, b);
	}
}

void	process_collect_bonus(t_game_data *g, size_t i)
{
	t_bonus	*b;

	b = (t_bonus *)g->bonus;
	mlx_set_instance_depth(&g->tile.collect[i]->instances[0], \
			Z_REMOVE);
	b->remove_collect = true;
	b->remove_collect_time[i] = mlx_get_time();
}

