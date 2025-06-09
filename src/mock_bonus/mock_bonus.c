/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:24:17 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 00:37:18 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*empty bonus functions*/

void	so_long_bonus(t_game_data *g)
{
	(void)g;
}

int	init_game_data_bonus(t_game_data *g)
{
	(void)g;
	return (0);
}

void	exit_game_reached_bonus(t_game_data *g)
{
	(void)g;
}

void	check_chars_bonus(t_game_data *g)
{
	(void)g;
}

void	load_game_images_bonus(t_game_data *g)
{
	(void)g;
}

void	add_game_tile_bonus(t_game_data *g, int x, int y, char c)
{
	(void)g;
	(void)x;
	(void)y;
	(void)c;
}

void	z_position_tiles_bonus(t_game_data *g)
{
	(void)g;
}

void	game_loop_bonus(void *param)
{
	(void)param;
}

void	free_everything_bonus(t_game_data *g)
{
	(void)g;
}

void	bonus_tiles_cleanup(t_game_data *g)
{
	(void)g;
}

void	process_position_bonus(t_game_data *g)
{
	(void)g;
}

void	process_collect_bonus(t_game_data *g, size_t i)
{
	(void)g;
	(void)i;
}

void	game_key_hook_bonus(t_game_data *g, keys_t key)
{
	(void)g;
	(void)key;
}
