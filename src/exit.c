/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 02:46:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/03 00:28:41 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game_data *g)
{
	ft_putendl("before my mlx cleanup");
	my_mlx_cleanup(g);
	ft_putendl("after my mlx cleanup");
	free_everything(g);
	ft_putendl("after free everything");
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




