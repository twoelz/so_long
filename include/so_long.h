/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:21:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/16 23:25:53 by tda-roch         ###   ########.fr       */
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

/* game dimensions */

# define WIDTH 1024
# define HEIGHT 768

# define TILE 96

/* Z positioning of sprites */
enum
{
	Z_SPACE = 0,
	Z_COLLECTIBLE = 1,
	Z_EXIT = 1,
	Z_PLAYER = 2,
	Z_WALL = 3,
};

# define ERROR_MSG "Error\n"

typedef enum e_map_error
{
	MAP_INVALID_EXTENSION,
	MAP_MULTIPLE_EXIT,
	MAP_NO_EXIT,
	MAP_MULTIPLE_START,
	MAP_NO_START,
	MAP_NO_COLLECTIBLE,
	MAP_NO_RECTANGLE,
	MAP_NO_WALLED,
	MAP_INVALID_PATH,
}	t_map_error;

typedef struct s_game_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			moves;
}	t_game_data;



// input.c
void		game_keyhook(mlx_key_data_t keydata, void *param);

// error.c
void		exit_after_mlx_error(void);

// exit.c

void		exit_game(t_game_data *g);
void		free_everything(t_game_data *g);

#endif