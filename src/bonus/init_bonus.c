/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 22:34:27 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/02 00:46:08 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_bonus(t_game_data *g)
{
	g->bonus.remove_collect = ft_calloc(g->item.total_collect + 1,
			sizeof(bool));
	if (!g->bonus.remove_collect)
		return (set_error_code(g, E_ALLOC));
	g->bonus.remove_collect_time = ft_calloc(g->item.total_collect + 1,
			sizeof(double));
	if (!g->bonus.remove_collect_time)
		return (set_error_code(g, E_ALLOC));
	return (E_SUCCESS);
}
