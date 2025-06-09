/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_images_disable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:24:48 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 15:26:18 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	disable_invisible_tiles(t_game_data *g)
{
	g->tile.exit_open->enabled = false;
	g->tile.player_left->enabled = false;
	g->tile.player_up_left->enabled = false;
	g->tile.player_up_right->enabled = false;
	g->tile.player_down_left->enabled = false;
	g->tile.player_down_right->enabled = false;
}

void	disable_player_images(t_game_data *g)
{
	g->tile.player_left->enabled = false;
	g->tile.player_right->enabled = false;
	g->tile.player_up_right->enabled = false;
	g->tile.player_up_left->enabled = false;
	g->tile.player_down_right->enabled = false;
	g->tile.player_down_left->enabled = false;
}
