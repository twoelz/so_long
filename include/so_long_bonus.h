/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:33:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/04 01:27:22 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "so_long.h"

// bonus/game_loop_bonus.c
void	game_loop_bonus(void *param);
void	loop_remove_collect(t_game_data *g);
void	adjust_remove_exit(t_game_data *g);
void	adjust_remove_collect(t_game_data *g, size_t i);

// bonus/so_long_bonus.c
void	so_long_bonus(t_game_data *g);
int		init_game_data_bonus(t_game_data *g);
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
