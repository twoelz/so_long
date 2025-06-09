/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_bonus_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:18:43 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 15:19:38 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_key_hook_bonus(t_game_data *g, keys_t key)
{
	(void)g;
	(void)key;
}

void	game_loop_bonus(void *param)
{
	(void)param;
}

int	init_game_data_bonus(t_game_data *g)
{
	(void)g;
	return (0);
}

void	load_game_images_bonus(t_game_data *g)
{
	(void)g;
}

void	process_collect_bonus(t_game_data *g, size_t i)
{
	(void)g;
	(void)i;
}
