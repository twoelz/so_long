/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:26:30 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/03 19:33:41 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_everything_bonus(t_game_data *g)
{
	safe_free((void **)&g->bonus.collect_point);
	safe_free_double(&g->bonus.remove_collect_time);
}
