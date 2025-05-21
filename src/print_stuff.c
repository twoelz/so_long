/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:07:28 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/21 02:14:25 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TODO: delete print dimensions
void	print_dimensions(t_game_data *g)
{
	ft_printf("width: %d\nheight: %d\n", g->width, g->height);
}

//TODO: delete print dimensions
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

void	print_player_coordinates(t_game_data *g)
{
	ft_printf("-player coordinates-\n|   x:%d   |\n|   y:%d   |\n", \
		g->player.x, g->player.y);
}
