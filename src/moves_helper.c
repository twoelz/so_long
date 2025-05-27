/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 21:44:59 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/27 21:48:38 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	hit_wall(t_game_data *g)
{
	process_position(g);
	ft_putendl(HIT_WALL_MSG);
}

void	clear_move_info(t_game_data *g)
{
	ft_putstr(CLEAR_TERMINAL_SEQUENCE);
	ft_putstr(CLEAR_TERMINAL_SEQUENCE);
	g->hit_wall = false;
	g->collected = false;
}
