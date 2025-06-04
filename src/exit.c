/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 02:46:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/04 02:11:59 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game_data *g)
{
	my_mlx_cleanup(g);
	free_everything(g);
	exit(EXIT_FAILURE);
}

void	exit_mlx_error(t_game_data *g, bool init)
{
	ft_putendl(E_ERROR_MSG);
	if (init)
		ft_putendl(E_MLX_INIT_ERROR_MSG);
	else
		ft_putendl(E_MLX_ERROR_MSG);
	ft_putendl(mlx_strerror(mlx_errno));
	exit_game(g);
}

void	close_game(t_game_data *g)
{
	ft_putendl(CLOSE_GAME_MSG);
	exit_game(g);
}




