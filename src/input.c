/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:42:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/27 21:47:49 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_key_hook(mlx_key_data_t k, void *param)
{
	t_game_data	*g;

	g = (t_game_data *)param;
	if (k.action == MLX_PRESS || k.action == MLX_REPEAT)
	{
		if (k.key == MLX_KEY_ESCAPE)
			close_game(g);
		if (g->game_over)
			return ;
		clear_move_info(g);
		if (k.key == MLX_KEY_A)
			move_left(g);
		else if (k.key == MLX_KEY_D)
			move_right(g);
		else if (k.key == MLX_KEY_W)
			move_up(g);
		else if (k.key == MLX_KEY_S)
			move_down(g);
		else
			return ;
		if (!g->game_over && !g->hit_wall && g->item.collectibles <= 0)
			ft_putendl(EXIT_OPEN_MSG);
		if (g->collected)
			ft_putendl(COLLECTED_MSG);
	}
}

void	game_close_button_hook(void *param)
{
	t_game_data	*g;

	g = (t_game_data *)param;
	close_game(g);
}
