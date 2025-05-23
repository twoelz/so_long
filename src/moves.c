/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:42:28 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/23 03:50:34 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hit_wall(void)
{
	ft_putendl("CAN'T GO, HIT WALL!");
}

void	move_left(t_game_data *g)
{
	if (g->ber[g->player.y][g->player.x - 1] == '1')
		return (hit_wall());
	g->player.x -= 1;
	process_position(g);
	ft_putendl("moved left");
}

void	move_right(t_game_data *g)
{
	if (g->ber[g->player.y][g->player.x + 1] == '1')
		return (hit_wall());
	g->player.x += 1;
	process_position(g);
	ft_putendl("moved right");
}

void	move_up(t_game_data *g)
{
	if (g->ber[g->player.y - 1][g->player.x] == '1')
		return (ft_putendl("CAN'T GO, HIT WALL!"));
	g->player.y -= 1;
	process_position(g);
	ft_putendl("moved up");
}

void	move_down(t_game_data *g)
{
	if (g->ber[g->player.y + 1][g->player.x] == '1')
		return (hit_wall());
	g->player.y += 1;
	process_position(g);
	ft_putendl("moved down");
}

void	process_position(t_game_data *g)
{
	g->moves++;
	ft_printf("%d moves\n", g->moves);
	if (g->ber[g->player.y][g->player.x] == 'C')
	{
		g->ber[g->player.y][g->player.x] = '0';
		g->items.collectibles--;
	}
	print_updated_ber(g);
}
