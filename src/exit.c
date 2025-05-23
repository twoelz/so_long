/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 02:46:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/23 03:37:29 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game_data *g)
{
	free_everything(g);
	mlx_close_window(g->mlx);
	mlx_terminate(g->mlx);
	exit(1);
}
