/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:26:30 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/06 02:14:51 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_everything_bonus(t_game_data *g)
{
	t_bonus	*b;

	b = (t_bonus *)g->bonus;
	if (b)
	{
		safe_free((void **)&b->collect_point);
		safe_free_double(&b->remove_collect_time);
		safe_free((void **)&b);
	}
}

void	bonus_tiles_cleanup(t_game_data *g)
{
	t_bonus	*b;

	b = (t_bonus *)g->bonus;
	mlx_delete_image(g->mlx, b->text_image);
	mlx_delete_image(g->mlx, b->space_1);
	mlx_delete_image(g->mlx, b->space_2);
	mlx_delete_image(g->mlx, b->space_3);
	mlx_delete_image(g->mlx, b->enemy_sprite);
}
