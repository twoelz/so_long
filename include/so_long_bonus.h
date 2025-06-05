/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:33:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/05 09:34:22 by tda-roch         ###   ########.fr       */
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


// bonus/game_loop_bonus.c
void	game_loop_bonus(void *param);
void	loop_remove_collect(t_game_data *g);
void	adjust_remove_exit(t_game_data *g);
void	adjust_remove_collect(t_game_data *g, size_t i);

// bonus/so_long_bonus.c
void	so_long_bonus(t_game_data *g);
int		init_game_data_bonus(t_game_data *g);
void	load_game_images_bonus(t_game_data *g);
void	add_game_tile_bonus(t_game_data *g, int x, int y, char c);
void	check_chars_bonus(t_game_data *g);
void	clear_buf_bonus(t_game_data *g);
void	record_item_positions(t_game_data *g);
void	put_str_bonus(t_game_data *g, char *string);
void	add_to_buf_bonus(t_game_data *g, char *string);
void	print_buf_bonus(t_game_data *g);

// bonus/free_everything_bonus.c
void	free_everything_bonus(t_game_data *g);

// bonus/process_position_bonus.c
void	process_position_bonus(t_game_data *g);

#endif
