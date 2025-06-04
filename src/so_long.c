/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:13:37 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/03 23:33:45 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(int argc, char **argv, bool is_bonus)
{
	t_game_data	g;

	ft_bzero(&g, sizeof(t_game_data));
	g.is_bonus = is_bonus;
	if (init_game_data(&g, argc, argv[1]))
		return (return_error(&g));
	mlx_set_setting(MLX_MAXIMIZED, false);
	g.mlx = mlx_init(g.width, g.height, "so long", true);
	if (!g.mlx)
		exit_mlx_error(&g, true);
	resize_window(&g);
	load_game_images(&g);
	add_game_tiles(&g);
	if (g.is_bonus)
		so_long_bonus(&g);
	mlx_key_hook(g.mlx, &game_key_hook, &g);
	mlx_close_hook(g.mlx, &game_close_button_hook, &g);
	mlx_loop_hook(g.mlx, &game_loop_hook, &g);
	mlx_loop(g.mlx);
	my_mlx_cleanup(&g);
	return (EXIT_SUCCESS);
}

int	init_game_data(t_game_data *g, int argc, char *ber_path)
{
	ft_bzero(&g->tile, sizeof(t_tiles));
	g->print_ber = PRINT_BER;
	init_error_messages(g);
	if (argc < 2)
		return (set_error_code(g, E_NO_PATH_ARG));
	g->ber_path = ber_path;
	if (validate_map(g))
		return (g->error_code);
	if (g->is_bonus)
	{
		if (init_game_data_bonus(g))
			return (g->error_code);
	}
	g->tile.collect = ft_calloc((g->item.total_collect + 1), \
		sizeof(mlx_image_t *));
	if (!g->tile.collect)
		return (E_ALLOC);
	return (g->error_code);
}

void	resize_window(t_game_data *g)
{
	int	width;
	int	height;
	int	divide;

	divide = 1;
	g->tilesiz = TILESIZ;
	mlx_get_monitor_size(0, &width, &height);
	while (g->width * (TILESIZ / divide) > width || \
			g->height * (TILESIZ / divide) > height)
	{
		if (TILESIZ / divide <= 3)
			break ;
		divide *= 2;
	}
	g->tilesiz = TILESIZ / divide;
	mlx_set_window_size(g->mlx, g->width * g->tilesiz, \
						g->height * g->tilesiz);
}


/*
TODO: exit on time?
*/
void	exit_game_reached(t_game_data *g)
{
	g->game_over_time = mlx_get_time();
	g->game_over = true;
	ft_putendl(EXIT_REACHED_MSG);
	ft_putendl(GAME_OVER_MSG);
	ft_putendl(AUTO_CLOSE_MSG);
	if (g->is_bonus)
	{
		g->bonus.remove_exit = true;
		return ;
	}
	g->tile.exit_open->enabled = false;
}

