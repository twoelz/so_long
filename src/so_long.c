/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:13:37 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/27 09:05:27 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	g;

	if (init_game_data(&g, argc, argv[1]))
		return (return_error(&g));
	mlx_set_setting(MLX_MAXIMIZED, false);
	g.mlx = mlx_init(g.width * TILE, g.height * TILE, "so long", true);
	if (!g.mlx)
		exit_mlx_init_error(&g);
	load_game_images(&g);
	add_game_tiles(&g);
	mlx_key_hook(g.mlx, &game_keyhook, &g);
	mlx_loop(g.mlx);
	mlx_terminate(g.mlx);
	return (EXIT_SUCCESS);
}

//TODO: check if bool is needed, if anything can go wrong here (returning false)
int	init_game_data(t_game_data *g, int argc, char *ber_path)
{
	ft_bzero(g, sizeof(t_game_data));
	init_error_messages(g);
	if (argc < 2)
		return (set_error_code(g, E_NO_PATH_ARG));
	g->ber_path = ber_path;
	if (!validate_map(g))
		return (g->error_code);
	return (g->error_code);
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
		while (g->tile.collectible->instances[i].x != g->player.x * TILE || \
				g->tile.collectible->instances[i].y != g->player.y * TILE)
			i++;
		g->tile.collectible->instances[i].enabled = false;
		if (g->item.collectibles <= 0)
		{
			g->tile.exit_closed->enabled = false;
			g->tile.exit_open->enabled = true;
		}
	}
	print_updated_ber(g);
	if (g->ber[g->player.y][g->player.x] == 'E' && g->item.collectibles <= 0)
		exit_game_reached(g);
}

void	exit_game_reached(t_game_data *g)
{
	ft_putendl(EXIT_REACHED_MSG);
	exit_game(g);
}
