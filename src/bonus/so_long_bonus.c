/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:26:01 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 15:09:10 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_chars_bonus(t_game_data *g)
{
	g->item.valid_chars = VALID_MAP_CHARS_BONUS;
}

int	init_game_data_bonus(t_game_data *g)
{
	t_bonus	*b;

	b = ft_calloc(1, sizeof(t_bonus));
	ft_bzero(b->enemy, sizeof(b->enemy));
	if (!b)
		return (set_error_code(g, E_ALLOC));
	g->bonus = b;
	b->remove_collect_time = ft_calloc(g->item.total_collect + 1,
			sizeof(double));
	if (!b->remove_collect_time)
		return (set_error_code(g, E_ALLOC));
	b->collect_point = ft_calloc(g->item.total_collect + 1,
			sizeof(t_point));
	if (!b->collect_point)
		return (set_error_code(g, E_ALLOC));
	b->animate_space_time = mlx_get_time();
	b->enemy_move_time = b->animate_space_time;
	b->current_enemy_speed = MIN_ENEMY_SPEED;
	fill_move_permutations(b->move_perm);
	fill_move_coordinates(b->move_coord);
	clear_buf_bonus(b);
	return (E_SUCCESS);
}

void	exit_game_reached_bonus(t_game_data *g)
{
	ft_putendl(YOU_WIN_MSG);
	((t_bonus *)g->bonus)->remove_exit = true;
}

void	game_lost(t_game_data *g, t_bonus *b)
{
	b->loose_overlay->enabled = true;
	game_over(g);
	ft_putstr(CLEAR_TERMINAL_SEQUENCE);
	ft_putstr(CLEAR_TERMINAL_SEQUENCE);
	ft_putendl(YOU_LOOSE_MSG);
	ft_putendl(GAME_OVER_MSG);
	ft_putendl(AUTO_CLOSE_MSG);
}

/* records item positions */
void	so_long_bonus(t_game_data *g)
{
	t_bonus	*b;
	size_t	i;

	b = (t_bonus *)g->bonus;
	i = 0;
	while (i < g->item.total_collect)
	{
		b->collect_point[i].x = g->tile.collect[i]->instances[0].x;
		b->collect_point[i].y = g->tile.collect[i]->instances[0].y;
		i++;
	}
	b->exit_point.x = g->tile.exit_open->instances[0].x;
	b->exit_point.y = g->tile.exit_open->instances[0].y;
}
