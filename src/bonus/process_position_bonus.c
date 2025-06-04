/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_position_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:24:51 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/04 02:01:17 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	process_position_bonus(t_game_data *g)
{
	add_to_buf_bonus(g, ft_itoa(g->moves));
	add_to_buf_bonus(g, " moves");
	print_buf_bonus(g);
}
