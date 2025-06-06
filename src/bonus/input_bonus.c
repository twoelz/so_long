/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:12:58 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/06 17:42:58 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_key_hook_bonus(t_game_data *g, keys_t key)
{
	if (key == MLX_KEY_M || key == MLX_KEY_V)
		place_random_enemy(g);
}
