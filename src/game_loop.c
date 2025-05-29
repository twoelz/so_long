/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:51:12 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/29 15:56:14 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_loop_hook(void *param)
{
	t_game_data	*g;

	g = (t_game_data *)param;
	if (g->game_over)
	{
		if (mlx_get_time() - g->game_over_time > 10)
			close_game(g);
	}
}
