/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:15:38 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/21 12:05:57 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Given a point (x/y coordinate struct) and a fixed width,
updates the pointer to the next coordinate.
Note1: this works for fixed-width coordinate maps only.
Note2: caller must check for map height (maximum y)
*/
void	next_point(t_point *p, int width)
{
	p->x++;
	if (p->x >= width)
	{
		p->x = 0;
		p->y++;
	}
}

void	set_player_coordinates(t_game_data *g)
{
	t_point	p;

	ft_bzero(&p, sizeof(p));
	while (p.y < g->height)
	{
		if (g->ber[p.y][p.x] == 'P')
		{
			g->player.x = p.x;
			g->player.y = p.y;
			return ;
		}
		next_point(&p, g->width);
	}
}

void	fill_reachable(t_game_data *g, char **ber, int x, int y)
{
	// if (x < 0 || y < 0 || x >= g->width || y >= g->height)
	// 	return ;
	if (ber[y][x] == '1')
		return ;
	ber[y][x] = '1';
	fill_reachable(g, ber, x + 1, y);
	fill_reachable(g, ber, x - 1, y);
	fill_reachable(g, ber, x, y + 1);
	fill_reachable(g, ber, x, y - 1);
}
