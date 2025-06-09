/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 22:56:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 14:09:06 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_loop_bonus(void *param)
{
	t_game_data	*g;
	t_bonus		*b;

	g = (t_game_data *)param;
	b = (t_bonus *)g->bonus;
	b->mlx_time = mlx_get_time();
	if (b->remove_collect)
		loop_remove_collect(g, b);
	if (b->remove_exit)
		adjust_remove_exit(g, b);
	if (b->mlx_time - b->animate_space_time > SPACE_ANIMATION_SPEED)
		animate_space(g, b);
	if (g->game_over)
		return ;
	if (b->total_enemies)
		move_enemies_if_needed(g, b);
}

void	move_enemies_if_needed(t_game_data *g, t_bonus *b)
{
	double	now;

	now = mlx_get_time();
	if (now - b->enemy_move_time > b->current_enemy_speed)
	{
		b->enemy_move_time = now;
		if (now >= TIME_TO_MAX_ENEMY_SPEED)
			b->current_enemy_speed = MAX_ENEMY_SPEED;
		if (b->current_enemy_speed != MAX_ENEMY_SPEED)
			b->current_enemy_speed = MIN_ENEMY_SPEED - \
				((MIN_ENEMY_SPEED - MAX_ENEMY_SPEED) * \
				(now / TIME_TO_MAX_ENEMY_SPEED));
		move_all_enemies(g);
	}
}
