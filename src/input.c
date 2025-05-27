/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:42:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/27 20:39:45 by tda-roch         ###   ########.fr       */
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
		clear_terminal();
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
	}
}

void	game_close_button_hook(void *param)
{
	t_game_data	*g;

	g = (t_game_data *)param;
	close_game(g);
}
