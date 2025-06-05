/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:33:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/05 13:59:59 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "so_long.h"

/* valid map chars bonus*/
# define VALID_MAP_CHARS_BONUS "01CEPVMF"

# define TILE_SPACE_1 "./media/space/ocean_1.png"
# define TILE_SPACE_2 "./media/space/ocean_2.png"
# define TILE_SPACE_3 "./media/space/ocean_3.png"
# define TILE_VILLAIN "./media/villain/villain.png"

/* safe buffer size for string messages on screen (image_text) */
# define BONUS_BUFFER_SIZE 4096

/* changes space sprite every (float) seconds */
# define SPACE_ANIMATION_SPEED 0.1


# define ENEMY_PATROL_CHARS "VMF"

/* bonus data */
typedef struct s_bonus
{
	mlx_image_t	*space_1;
	mlx_image_t	*space_2;
	mlx_image_t	*space_3;
	mlx_image_t	*enemy;
	mlx_image_t	*text_image;
	t_point		exit_point;
	t_point		*collect_point;
	char		buf[BONUS_BUFFER_SIZE];
	size_t		buf_end;
	double		mlx_time;
	double		*remove_collect_time;
	double		animate_space_time;
	size_t		visible_space;
	bool		remove_collect;
	bool		remove_exit;
}	t_bonus;

// bonus/game_loop_bonus.c
void	game_loop_bonus(void *param);
void	loop_remove_collect(t_game_data *g, t_bonus *b);
void	adjust_remove_exit(t_game_data *g, t_bonus *b);
void	adjust_remove_collect(t_game_data *g, t_bonus *b, size_t i);
void	animate_space(t_game_data *g, t_bonus *b);

// bonus/so_long_bonus.c
void	so_long_bonus(t_game_data *g);
int		init_game_data_bonus(t_game_data *g);
void	exit_game_reached_bonus(t_game_data *g);
void	load_game_images_bonus(t_game_data *g);
void	add_game_tile_bonus(t_game_data *g, int x, int y, char c);
void	z_position_tiles_bonus(t_game_data *g);
void	check_chars_bonus(t_game_data *g);
void	clear_buf_bonus(t_bonus *b);
void	record_item_positions(t_game_data *g);
void	put_str_bonus(t_game_data *g, t_bonus *b);
void	add_to_buf_bonus(t_bonus *b, char *string);
void	print_buf_bonus(t_game_data *g, t_bonus *b);

// bonus/free_everything_bonus.c
void	free_everything_bonus(t_game_data *g);
void	bonus_tiles_cleanup(t_game_data *g);


// bonus/process_position_bonus.c
void	process_position_bonus(t_game_data *g);
void	process_collect_bonus(t_game_data *g, size_t i);

#endif
