/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:13:37 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/18 18:16:09 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_extension(char *map_path, int *error_code)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len < 4 || \
			map_path[len - 4] != '.' || \
			map_path[len - 3] != 'b' || \
			map_path[len - 2] != 'e' || \
			map_path[len - 1] != 'r')
		*error_code = MAP_INVALID_EXTENSION;
	return (*error_code);
}

int	validate_map(t_game_data *g, char *map_path)
{
	if (validate_extension(map_path, &g->error_code))
		return (g->error_code);
	ft_putnbr_fd(g->moves, STDOUT_FILENO);
	return (g->error_code);
}

//TODO: check if bool is needed, if anything can go wrong here (returning false)
int	init_game_data(t_game_data *g, char *map_path)
{
	ft_bzero(g, sizeof(t_game_data));
	if (!validate_map(g, map_path))
		return (g->error_code);
	return (g->error_code);
}


int	main(int argc, char **argv)
{
	t_game_data	g;

	if (argc < 2)
		return (return_error(MAP_NO_PATH_ARGUMENT));
	if (init_game_data(&g, argv[1]))
		return (return_error(g.error_code));

	// mlx_image_t	*img;

	mlx_set_setting(MLX_MAXIMIZED, false);
	g.mlx = mlx_init(WIDTH, HEIGHT, "so long", true);
	if (!g.mlx)
		exit_after_mlx_error();

	/* Do stuff */

	g.img = mlx_new_image(g.mlx, 256, 256);
	if (!g.img || (mlx_image_to_window(g.mlx, g.img, 0, 0) < 0))
		exit_after_mlx_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(g.img, 0, 0, 0xFF0000FF);

	// hook registers
	mlx_key_hook(g.mlx, &game_keyhook, &g);
	// mlx_key_hook(g.mlx, &move_key_hook, &map);
	// mlx_loop_hook(mlx, &game_keyhook, NULL);

	// MAIN LOOP
	mlx_loop(g.mlx);
	mlx_terminate(g.mlx);
	return (EXIT_SUCCESS);
}
