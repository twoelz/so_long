/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:13:37 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/16 03:09:25 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	init_game_data(t_game_data *g)
{
	g->moves = 0;
	return (true);
}


int	main(void)
{
	t_game_data	g;
	if (!init_game_data(&g))
	{
		ft_putstr_fd("TODO: error message\n", STDERR_FILENO);
	}
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
