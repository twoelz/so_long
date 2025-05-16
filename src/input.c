/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:42:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/16 03:06:59 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO: replace ft_putstr_fd with ft_putstr or ft_printf?
void	game_keyhook(mlx_key_data_t k, void *param)
{
	t_game_data	*g;

	g = (t_game_data *)param;
	if (k.action == MLX_PRESS || k.action == MLX_REPEAT)
	{
		if (k.key == MLX_KEY_A)
			ft_putstr_fd("go left\n", STDOUT_FILENO);
		else if (k.key == MLX_KEY_D)
			ft_putstr_fd("go right\n", STDOUT_FILENO);
		else if (k.key == MLX_KEY_W)
			ft_putstr_fd("go up\n", STDOUT_FILENO);
		else if (k.key == MLX_KEY_S)
			ft_putstr_fd("go down\n",STDOUT_FILENO);
		else if (k.key == MLX_KEY_ESCAPE)
			return (exit_game(g));
		else
			return ;
		g->moves++;
		ft_putnbr_fd(g->moves, STDOUT_FILENO);
		ft_putstr_fd(" moves\n", STDOUT_FILENO);
	}
}
