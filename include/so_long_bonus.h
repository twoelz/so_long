/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:33:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/03 13:37:44 by tda-roch         ###   ########.fr       */
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

// bonus/init_bonus.c
int		init_bonus(t_game_data *g);
void	record_item_positions(t_game_data *g);

#endif
