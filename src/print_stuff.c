/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:07:28 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 20:07:52 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TODO: delete print dimensions
void	print_dimensions(t_game_data *g)
{
	ft_printf("width: %d\nheight: %d\n", g->width, g->height);
}

//TODO: delete print dimensions
void	print_ber(t_game_data *g)
{
	int	y;

	y = 0;
	while (y < g->height)
	{
		ft_putendl(g->ber[y]);
		y++;
	}
}
