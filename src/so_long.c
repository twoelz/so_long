/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:13:37 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/19 14:35:58 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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

int	main(int argc, char **argv)
{
	t_game_data	g;

	if (init_game_data(&g, argc, argv[1]))
		return (return_error(&g));

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
	// mlx_loop_hook(mlx, &game_keyhook, NULL);

	// MAIN LOOP
	mlx_loop(g.mlx);
	mlx_terminate(g.mlx);
	return (EXIT_SUCCESS);
}
