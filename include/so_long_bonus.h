/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:33:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/07 05:23:56 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <math.h>
# include "so_long.h"

/* valid map chars bonus (adds enemy chars)*/
# define VALID_MAP_CHARS_BONUS "01CEPVMF"
# define ENEMY_CHARS "VMF"

/* bonus tiles paths */
# define TILE_SPACE_1 "./media/space/ocean_1.png"
# define TILE_SPACE_2 "./media/space/ocean_2.png"
# define TILE_SPACE_3 "./media/space/ocean_3.png"
# define TILE_ENEMY "./media/enemy/norminette.png"

/* bonus overlay paths */
# define OVERLAY_WIN "./media/overlay/mermaid_win.png"
# define OVERLAY_LOOSE "./media/overlay/rick_loose.png"

/* bonus error messages */
# define E_TOO_MANY_ENEMIES_MSG "too many enemies in map file"

/* bonus messages */
# define YOU_LOOSE_MSG "Norminette said: line too long!\nYou lost!"

/* safe buffer size for string messages on screen (image_text) */
# define BONUS_BUFFER_SIZE 4096

/*  knuth multiplicative hash constant */
# define KNUTH 2654435761u

/* changes space sprite every (float) seconds */
# define SPACE_ANIMATION_SPEED 0.1

/* ENEMY MOVEMENT */
# define MIN_ENEMY_SPEED 1.0

# define MAX_ENEMY_SPEED 0.3

# define ENEMY_SPEED_STEP 3.0

/* bonus data */
typedef struct s_bonus
{
	mlx_image_t	*text_image;
	mlx_image_t	*space_1;
	mlx_image_t	*space_2;
	mlx_image_t	*space_3;
	mlx_image_t	*enemy_sprite;
	mlx_image_t	*you_win;
	mlx_image_t	*you_loose;
	t_point		exit_point;
	t_point		*collect_point;
	t_point		enemy[500];
	char		buf[BONUS_BUFFER_SIZE];
	size_t		buf_end;
	double		mlx_time;
	double		*remove_collect_time;
	double		animate_space_time;
	size_t		visible_space;
	bool		remove_collect;
	bool		remove_exit;
	size_t		total_enemies;
	int			move_perm[24][4];
	t_point		move_coord[4];
}	t_bonus;

// bonus/enemy.c
size_t	count_enemy_free_spots(t_game_data *g, t_bonus *b);
bool	enemy_in_point(t_bonus *b, t_point p);
void	fill_move_permutations(int arr[24][4]);
void	fill_move_coordinates(t_point arr[4]);
void	move_all_enemies(t_game_data *g);

// bonus/error_bonus.c
void	warning_too_many_enemies(void);

// bonus/game_loop_bonus.c
void	game_loop_bonus(void *param);
void	loop_remove_collect(t_game_data *g, t_bonus *b);
void	adjust_remove_exit(t_game_data *g, t_bonus *b);
void	adjust_remove_collect(t_game_data *g, t_bonus *b, size_t i);
void	animate_space(t_game_data *g, t_bonus *b);

// bonus/input_bonus.c
void	game_key_hook_bonus(t_game_data *g, keys_t key);

// bonus/so_long_bonus.c
void	so_long_bonus(t_game_data *g);
int		init_game_data_bonus(t_game_data *g);
void	exit_game_reached_bonus(t_game_data *g);
void	load_game_images_bonus(t_game_data *g);
void	add_enemy_to_coordinates(t_game_data *g, t_bonus *b, int x, int y);
void	add_game_tile_bonus(t_game_data *g, int x, int y, char c);
void	z_position_tiles_bonus(t_game_data *g);
void	check_chars_bonus(t_game_data *g);
void	clear_buf_bonus(t_bonus *b);
void	record_item_positions(t_game_data *g);
void	put_str_bonus(t_game_data *g, t_bonus *b);
void	add_to_buf_bonus(t_bonus *b, char *string);
void	print_buf_bonus(t_game_data *g, t_bonus *b);
void	place_random_enemy(t_game_data *g);

// bonus/free_everything_bonus.c
void	free_everything_bonus(t_game_data *g);
void	bonus_tiles_cleanup(t_game_data *g);

// bonus/process_position_bonus.c
void	process_position_bonus(t_game_data *g);
void	process_collect_bonus(t_game_data *g, size_t i);

#endif
