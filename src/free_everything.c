/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 23:33:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/03 19:33:08 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_everything(t_game_data *g)
{
	safe_free_2d_char(&g->ber);
	safe_free((void **)&g->tile.collect);
	if (g->is_bonus)
		free_everything_bonus(g);
}
