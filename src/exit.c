/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 02:46:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/26 15:18:01 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game_data *g)
{
	free_everything(g);
	mlx_close_window(g->mlx);
	mlx_terminate(g->mlx);
	exit(EXIT_FAILURE);
}

// TODO: REMOVE fprintf and see if printing those errors are needed
// TODO: add appropriate MSG from header.
void	exit_mlx_init_error(t_game_data *g)
{
	ft_putendl("mlx initialization error");
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	// free_everything(g);
	// exit(EXIT_FAILURE);
	exit_game(g);
}

// TODO: REMOVE fprintf and see if printing those errors are needed
// TODO: add appropriate MSG from header.
void	exit_mlx_error(t_game_data *g)
{
	ft_putendl("mlx error");
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit_game(g);
}
