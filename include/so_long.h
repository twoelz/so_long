/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:21:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/28 19:36:24 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"
# include "libft.h"

/* game tile png paths */
# define TILE_PLAYER_RIGHT "./media/vela_right.png"
# define TILE_PLAYER_LEFT "./media/vela_left.png"
# define TILE_PLAYER_UP_RIGHT "./media/vela_up_right.png"
# define TILE_PLAYER_UP_LEFT "./media/vela_up_left.png"
# define TILE_PLAYER_DOWN_RIGHT "./media/vela_down_right.png"
# define TILE_PLAYER_DOWN_LEFT "./media/vela_down_left.png"
# define TILE_WALL "./media/pebbles.png"
# define TILE_SPACE "./media/brush_water.png"
# define TILE_COLLECTIBLE "./media/cetus.png"
# define TILE_EXIT_CLOSED "./media/pyxis_closed.png"
# define TILE_EXIT_OPEN "./media/pyxis_open.png"

/* game dimensions */
# define WIDTH 1024
# define HEIGHT 768
# define TILESIZ 96

/* valid map chars */
# define VALID_MAP_CHARS "01CEP"

/* Z position of tiles */
enum
{
	Z_SPACE,
	Z_COLLECTIBLE,
	Z_EXIT,
	Z_PLAYER,
	Z_WALL,
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
	E_NO_REACH_COLLECT,
	E_NO_REACH_EXIT,
}	t_error_codes;

/* ERROR MESSAGES */
# define ERROR_MSG "Error"
# define E_SUCCESS_MSG ""
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
# define E_NO_REACH_COLLECT_MSG "Invalid map: unreacheable collectible."
# define E_NO_REACH_EXIT_MSG "Invalid map: unreacheable exit."

/* GAME MESSAGES */
# define MOVED_LEFT_MSG "moved left"
# define MOVED_RIGHT_MSG "moved right"
# define MOVED_UP_MSG "moved up"
# define MOVED_DOWN_MSG "moved down"
# define COLLECTED_MSG "collected cetus!"
# define EXIT_OPEN_MSG "pyxis is open, let's catch it!"
# define EXIT_CLOSED_MSG "pyxis is closed. go catch all the ceti!"
# define EXIT_REACHED_MSG "set sail, we are going hooome!!!\n"
# define GAME_OVER_MSG "game over. press ESC or close window to exit"
# define HIT_WALL_MSG "you found the shore...\nkeep sailing, dear Vela!"
# define CLOSE_GAME_MSG "goodbye!"

/* CLEAR TERMINAL ANSI SEQUENCE */
# define CLEAR_TERMINAL_SEQUENCE "\033[3J\033[H\033[2J"

# define PRINT_BER false

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map_items
{
	size_t		spaces;
	size_t		collectibles;
	size_t		exits;
	size_t		players;
}	t_map_items;

typedef struct s_tiles
{
	bool		initialized;
	mlx_image_t	*wall;
	mlx_image_t	*space;
	mlx_image_t	*collectible;
	mlx_image_t	*exit_closed;
	mlx_image_t	*exit_open;
	mlx_image_t	*player_right;
	mlx_image_t	*player_left;
	mlx_image_t	*player_up_right;
	mlx_image_t	*player_up_left;
	mlx_image_t	*player_down_right;
	mlx_image_t	*player_down_left;
}	t_tiles;

typedef struct s_game_data
{
	mlx_t		*mlx;
	t_tiles		tile;
	t_point		player;
	t_map_items	item;
	int			width;
	int			height;
	int			tilesiz;
	int			moves;
	int			error_code;
	char		*error_message[19];
	char		*ber_path;
	char		**ber;
	bool		print_ber;
	bool		looking_left;
	bool		hit_wall;
	bool		collected;
	bool		game_over;
}	t_game_data;

// so_long.c
void	exit_game_reached(t_game_data *g);
int		init_game_data(t_game_data *g, int argc, char *ber_path);
void	process_position(t_game_data *g);
void	resize_window(t_game_data *g);

// coordinates.c
void	next_point(t_point *p, int width);
void	set_player_coordinates(t_game_data *g);
void	fill_reachable(t_game_data *g, char **ber, int x, int y);

// error.c

void	init_error_messages(t_game_data *g);
int		set_error_code(t_game_data *g, int error_code);
void	set_error_message(char **error_message, \
			int error_code, char *message);
int		return_error(t_game_data *g);

// exit.c
void	exit_game(t_game_data *g);
void	exit_mlx_init_error(t_game_data *g);
void	exit_mlx_error(t_game_data *g);
void	close_game(t_game_data *g);

// free_everything.c
void	free_everything(t_game_data *g);
void	safe_free_2d_char(char ***ptr);

// input.c
void	game_key_hook(mlx_key_data_t keydata, void *param);
void	game_close_button_hook(void *param);

// tile_image_change.c
void	move_player_image_up(t_game_data *g);
void	move_player_image_down(t_game_data *g);
void	move_player_image_left(t_game_data *g);
void	move_player_image_right(t_game_data *g);
void	disable_player_images(t_game_data *g);

// tile_images_add.c

void	add_game_tiles(t_game_data *g);
void	add_game_tile(t_game_data *g, int x, int y);
void	tile_win(t_game_data *g, mlx_image_t *image, int x, int y);
void	z_position_tiles(t_game_data *g);
void	disable_invisible_tiles(t_game_data *g);

// tile_images_load.c

void	load_game_images(t_game_data *g);
void	png_to_image(t_game_data *g, mlx_image_t **image, char *png_path);

// moves.c
void	move_left(t_game_data *g);
void	move_right(t_game_data *g);
void	move_up(t_game_data *g);
void	move_down(t_game_data *g);

// moves_helper.c
void	clear_move_info(t_game_data *g);
void	hit_wall(t_game_data *g);

// my_mlx_cleanup.c
void	my_mlx_cleanup(t_game_data *g);
void	my_tiles_cleanup(t_game_data *g);

// print_stuff.c
void	print_ber(t_game_data *g, char ***ber);
void	print_updated_ber(t_game_data *g);
void	print_player_coordinates(t_game_data *g);

// validate_map.c
int		validate_map(t_game_data *g);
int		load_ber(t_game_data *g, char ***ber);
int		check_rectangular(t_game_data *g);
int		check_chars(t_game_data *g);
int		check_walled(t_game_data *g);

// validate_map_file.c
int		check_extension(char *map_path, int *error_code);
int		check_path(char *map_path, int *error_code);
int		check_minumum_size(t_game_data *g);

// validate_map_items.c
int		validate_map_items(t_game_data *g);
void	count_map_items(t_game_data *g, t_map_items *items, char ***ber);
int		check_number_of_items(t_game_data *g);
int		check_reachable_items(t_game_data *g);

// utils/str_utils.c
int		found_in_str(char c_to_find, char *str);
size_t	ft_strlen_exclude_newline(const char *str);

#endif