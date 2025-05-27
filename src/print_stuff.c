/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:07:28 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/27 21:45:26 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TODO: delete print ber
void	print_ber(t_game_data *g, char ***ber)
{
	int	y;

	y = 0;
	while (y < g->height)
	{
		ft_putendl((*ber)[y]);
		y++;
	}
}

void	print_updated_ber(t_game_data *g)
{
	t_point	p;
	char	c;

	ft_bzero(&p, sizeof(p));
	while (p.y < g->height)
	{
		c = g->ber[p.y][p.x];
		if (p.x == g->player.x && p.y == g->player.y)
			c = 'P';
		ft_putchar(c);
		if (p.x == g->width - 1)
			ft_putchar('\n');
		next_point(&p, g->width);
	}
}

void	print_player_coordinates(t_game_data *g)
{
	ft_printf("-player coordinates-\n|   x:%d   |\n|   y:%d   |\n", \
		g->player.x, g->player.y);
}
