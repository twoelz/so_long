/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:42:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 13:27:19 by tda-roch         ###   ########.fr       */
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
			ft_putstr("go left\n");
		else if (k.key == MLX_KEY_D)
			ft_putstr("go right\n");
		else if (k.key == MLX_KEY_W)
			ft_putstr("go up\n");
		else if (k.key == MLX_KEY_S)
			ft_putstr("go down\n");
		else if (k.key == MLX_KEY_ESCAPE)
			return (exit_game(g));
		else
			return ;
		g->moves++;
		ft_putnbr(g->moves);
		ft_putstr(" moves\n");
	}
}
