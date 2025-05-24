/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:42:28 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/24 12:58:35 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hit_wall(t_game_data *g)
{
	process_position(g);
	ft_putendl(HIT_WALL_MSG);
}

void	move_left(t_game_data *g)
{
	if (g->ber[g->player.y][g->player.x - 1] == '1')
		return (hit_wall(g));
	g->moves++;
	g->player.x -= 1;
	process_position(g);
	ft_putendl(MOVED_LEFT_MSG);
}

void	move_right(t_game_data *g)
{
	if (g->ber[g->player.y][g->player.x + 1] == '1')
		return (hit_wall(g));
	g->moves++;
	g->player.x += 1;
	process_position(g);
	ft_putendl(MOVED_RIGHT_MSG);
}

void	move_up(t_game_data *g)
{
	if (g->ber[g->player.y - 1][g->player.x] == '1')
		return (hit_wall(g));
	g->moves++;
	g->player.y -= 1;
	process_position(g);
	ft_putendl(MOVED_UP_MSG);
}

void	move_down(t_game_data *g)
{
	if (g->ber[g->player.y + 1][g->player.x] == '1')
		return (hit_wall(g));
	g->moves++;
	g->player.y += 1;
	process_position(g);
	ft_putendl(MOVED_DOWN_MSG);
}
