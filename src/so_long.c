/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:13:37 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/28 19:44:45 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	g;

	if (init_game_data(&g, argc, argv[1]))
		return (return_error(&g));
	mlx_set_setting(MLX_MAXIMIZED, false);
	g.mlx = mlx_init(g.width, g.height, "so long", true);
	if (!g.mlx)
		exit_mlx_init_error(&g);
	resize_window(&g);
	load_game_images(&g);
	add_game_tiles(&g);
	mlx_key_hook(g.mlx, &game_key_hook, &g);
	mlx_close_hook(g.mlx, &game_close_button_hook, &g);
	mlx_loop(g.mlx);
	my_mlx_cleanup(&g);
	return (EXIT_SUCCESS);
}

int	init_game_data(t_game_data *g, int argc, char *ber_path)
{
	ft_bzero(g, sizeof(t_game_data));
	g->tile.initialized = false;
	init_error_messages(g);
	if (argc < 2)
		return (set_error_code(g, E_NO_PATH_ARG));
	g->ber_path = ber_path;
	if (validate_map(g))
		return (g->error_code);
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
	g->mlx->width = g->width * g->tilesiz;
	g->mlx->height = g->height * g->tilesiz;
	mlx_set_window_size(g->mlx, g->width * g->tilesiz, \
						g->height * g->tilesiz);
}

void	process_position(t_game_data *g)
{
	size_t	i;

	ft_printf("%d moves\n", g->moves);
	if (g->ber[g->player.y][g->player.x] == 'C')
	{
		g->ber[g->player.y][g->player.x] = '0';
		g->item.collectibles--;
		i = 0;
		while (g->tile.collectible->instances[i].x != g->player.x * g->tilesiz \
			|| g->tile.collectible->instances[i].y != g->player.y * g->tilesiz)
			i++;
		g->tile.collectible->instances[i].enabled = false;
		g->collected = true;
		if (g->item.collectibles <= 0)
		{
			g->tile.exit_closed->enabled = false;
			g->tile.exit_open->enabled = true;
		}
	}
	if (PRINT_BER)
		print_updated_ber(g);
	if (g->ber[g->player.y][g->player.x] == 'E' && g->item.collectibles > 0)
		ft_putendl(EXIT_CLOSED_MSG);
	if (g->ber[g->player.y][g->player.x] == 'E' && g->item.collectibles <= 0)
		exit_game_reached(g);
}

/*
TODO: exit on time?
*/
void	exit_game_reached(t_game_data *g)
{
	g->game_over = true;
	g->tile.exit_open->enabled = false;
	ft_putendl(EXIT_REACHED_MSG);
	ft_putendl(GAME_OVER_MSG);
}

