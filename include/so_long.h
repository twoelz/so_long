/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:21:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/19 02:10:23 by tda-roch         ###   ########.fr       */
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
# include <fcntl.h>
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

typedef enum e_error_codes
{
	INIT_GAME_SUCCESS,
	MAP_NO_PATH_ARGUMENT,
	MAP_INVALID_EXTENSION,
	MAP_INVALID_PATH,
	MAP_FILE_EMPTY,
	MAP_READ_ERROR,
	MAP_MINIMUM_SIZE,
	MAP_MULTIPLE_EXIT,
	MAP_NO_EXIT,
	MAP_MULTIPLE_START,
	MAP_NO_START,
	MAP_NO_COLLECTIBLE,
	MAP_NO_RECTANGLE,
	MAP_NO_WALLED,

}	t_error_codes;

# define ERROR_MSG "Error\n"

# define MAP_SUCCESS_MSG "loading map...\n"
# define MAP_NO_PATH_ARGUMENT_MSG "Missing map argument.\n"
# define MAP_INVALID_EXTENSION_MSG "Invalid map extension.\n"
# define MAP_INVALID_PATH_MSG "Invalid path: no map found.\n"
# define MAP_FILE_EMPTY_MSG "Empty map file.\n"
# define MAP_READ_ERROR_MSG "Reading map file failed.\n"
# define MAP_MINIMUM_SIZE_MSG "Map smaller than minimum valid size.\n"
# define MAP_MULTIPLE_EXIT_MSG "Invalid map: multiple exits found.\n"
# define MAP_NO_EXIT_MSG "Invalid map: no exit found.\n"
# define MAP_MULTIPLE_START_MSG "Invalid map: multiple start positions found.\n"
# define MAP_NO_START_MSG "Invalid map: no start position found.\n"
# define MAP_NO_COLLECTIBLE_MSG "Invalid map: no collectible found.\n"
# define MAP_NO_RECTANGLE_MSG "Invalid map: not rectangular.\n"
# define MAP_NO_WALLED_MSG "Invalid map: not fully walled.\n"

typedef struct s_game_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			width;
	int			height;
	int			moves;
	int			error_code;
}	t_game_data;

// input.c
void	game_keyhook(mlx_key_data_t keydata, void *param);

// error.c
int		set_error_code(t_game_data *g, int error_code);
void	exit_after_mlx_error(void);
int		return_error(int error_code);

// exit.c
void	exit_game(t_game_data *g);
void	free_everything(t_game_data *g);

// validate_file.c
int		validate_extension(char *map_path, int *error_code);
int		validate_path(char *map_path, int *error_code);
int		validate_empty(int fd, int *error_code);

// validate_map.c
int		validate_map(t_game_data *g, char *map_path);
int		validate_map_dimensions(t_game_data *g, char *map_path);

#endif