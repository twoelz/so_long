/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:42:28 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/27 21:48:29 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game_data *g)
{
	if (g->ber[g->player.y][g->player.x - 1] == '1')
		return (hit_wall(g));
	g->moves++;
	g->player.x -= 1;
	move_player_image_left(g);
	process_position(g);
	if (!g->game_over)
		ft_putendl(MOVED_LEFT_MSG);
}

void	move_right(t_game_data *g)
{
	if (g->ber[g->player.y][g->player.x + 1] == '1')
		return (hit_wall(g));
	g->moves++;
	g->player.x += 1;
	move_player_image_right(g);
	process_position(g);
	if (!g->game_over)
		ft_putendl(MOVED_RIGHT_MSG);
}

void	move_up(t_game_data *g)
{
	if (g->ber[g->player.y - 1][g->player.x] == '1')
		return (hit_wall(g));
	g->moves++;
	g->player.y -= 1;
	move_player_image_up(g);
	process_position(g);
	if (!g->game_over)
		ft_putendl(MOVED_UP_MSG);
}

void	move_down(t_game_data *g)
{
	if (g->ber[g->player.y + 1][g->player.x] == '1')
		return (hit_wall(g));
	g->moves++;
	g->player.y += 1;
	move_player_image_down(g);
	process_position(g);
	if (!g->game_over)
		ft_putendl(MOVED_DOWN_MSG);
}
