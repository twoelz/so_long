/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:21:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/15 12:45:45 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame and the
   current frame.

typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;
*/

/*
this file is just to test creating an mlx project, as a prerequisite for
the 42 cursus project "so_long"
*/
#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# define WIDTH 1024
# define HEIGHT 768

typedef struct s_game_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_game_data;

// input.c
void		game_keyhook(mlx_key_data_t keydata, void *param);

// error.c
void		exit_after_mlx_error(void);

#endif