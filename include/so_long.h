/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:21:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 20:44:50 by tda-roch         ###   ########.fr       */
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

/* valid map chars */
# define VALID_MAP_CHARS "01CEP"

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
	E_SUCCESS,
	E_ALLOC,
	E_NO_PATH_ARG,
	E_INVALID_EXT,
	E_INVALID_PATH,
	E_FILE_EMPTY,
	E_READ_ERROR,
	E_MINIMUM_SIZE,
	E_INVALID_CHAR,
	E_NO_RECTANGLE,
	E_NO_WALLED,
	E_NO_COLLECT,
	E_NO_START,
	E_NO_EXIT,
	E_MULTI_START,
	E_MULTI_EXIT,
}	t_error_codes;

# define ERROR_MSG "Error"
# define E_SUCCESS_MSG "loading map..."
# define E_ALLOC_MSG "allocation error"
# define E_NO_PATH_ARG_MSG "Missing map argument."
# define E_INVALID_EXT_MSG "Invalid map extension."
# define E_INVALID_PATH_MSG "Invalid path: no map found."
# define E_FILE_EMPTY_MSG "Empty map file."
# define E_READ_ERROR_MSG "Reading map file failed."
# define E_MINIMUM_SIZE_MSG "Map smaller than minimum valid size."
# define E_INVALID_CHAR_MSG "Invalid map: invalid character found."
# define E_NO_RECTANGLE_MSG "Invalid map: not rectangular."
# define E_NO_WALLED_MSG "Invalid map: not fully walled."
# define E_NO_COLLECT_MSG "Invalid map: no collectible found."
# define E_NO_START_MSG "Invalid map: no start position found."
# define E_NO_EXIT_MSG "Invalid map: no exit found."
# define E_MULTI_START_MSG "Invalid map: multiple start positions found."
# define E_MULTI_EXIT_MSG "Invalid map: multiple exits found."

typedef struct s_game_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			width;
	int			height;
	int			moves;
	int			error_code;
	char		*error_message[17];
	char		*ber_path;
	char		**ber;
}	t_game_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// input.c
void	game_keyhook(mlx_key_data_t keydata, void *param);

// coordinates.c
void	next_point(t_point *p, int width);

// error.c
void	exit_after_mlx_error(void);
void	init_error_messages(t_game_data *g);
int		set_error_code(t_game_data *g, int error_code);
void	set_error_message(char **error_message, \
			int error_code, char *message);
int		return_error(t_game_data *g);

// free_everything.c
void	free_everything(t_game_data *g);

// exit.c
void	exit_game(t_game_data *g);

// print_stuff.c
void	print_dimensions(t_game_data *g);
void	print_ber(t_game_data *g);

// validate_file.c
int		validate_extension(char *map_path, int *error_code);
int		validate_path(char *map_path, int *error_code);
int		validate_empty(int fd, int *error_code);

// validate_map.c
int		validate_map(t_game_data *g);
int		validate_minumum_size(t_game_data *g);

// utils/str_utils.c
int		found_in_str(char c_to_find, char *str);
size_t	ft_strlen_exclude_newline(const char *str);

#endif