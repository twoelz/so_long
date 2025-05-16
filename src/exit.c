/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 02:46:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/16 03:11:10 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_everything(t_game_data *g)
{
	ft_putnbr_fd(g->moves, STDOUT_FILENO);
	ft_putstr_fd("free all allocated here\n", STDOUT_FILENO);
}

void	exit_game(t_game_data *g)
{
	free_everything(g);
	mlx_close_window(g->mlx);
}
