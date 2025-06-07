/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 23:26:01 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/07 02:49:20 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_long_bonus(t_game_data *g)
{
	record_item_positions(g);
}

int	init_game_data_bonus(t_game_data *g)
{
	t_bonus	*b;

	b = ft_calloc(1, sizeof(t_bonus));
	if (!b)
		return (set_error_code(g, E_ALLOC));
	g->bonus = b;
	b->remove_collect_time = ft_calloc(g->item.total_collect + 1,
			sizeof(double));
	if (!b->remove_collect_time)
		return (set_error_code(g, E_ALLOC));
	b->collect_point = ft_calloc(g->item.total_collect + 1,
			sizeof(t_point));
	if (!b->collect_point)
		return (set_error_code(g, E_ALLOC));
	b->animate_space_time = mlx_get_time();
	fill_move_permutations(b->move_perm);
	fill_move_coordinates(b->move_coord);
	clear_buf_bonus(b);
	return (E_SUCCESS);
}

void	add_resized_overlay(t_game_data *g, mlx_image_t *overlay,
			int width, int height)
{
	double	proportion;

	proportion = fmin((double)width / (double)overlay->width,
			(double)height / (double)overlay->height);
	mlx_resize_image(overlay,
		overlay->width * proportion,
		overlay->height * proportion);
	tile_win(g, overlay, (width - overlay->width) / 2,
		(height - overlay->height) / 2);
	mlx_set_instance_depth(&overlay->instances[0], Z_OVERLAY);
	overlay->enabled = false;
}

void	add_win_loose_overlays(t_game_data *g, t_bonus *b)
{
	int		width;
	int		height;

	width = g->width * g->tilesiz;
	height = g->height * g->tilesiz;
	add_resized_overlay(g, b->you_win, width, height);
	add_resized_overlay(g, b->you_loose, width, height);
}

void	load_game_images_bonus(t_game_data *g)
{
	t_bonus	*b;

	b = (t_bonus *)g->bonus;
	png_to_image(g, &b->space_1, TILE_SPACE_1);
	png_to_image(g, &b->space_2, TILE_SPACE_2);
	png_to_image(g, &b->space_3, TILE_SPACE_3);
	png_to_image(g, &b->enemy_sprite, TILE_ENEMY);
	png_to_image(g, &b->you_win, OVERLAY_WIN);
	png_to_image(g, &b->you_loose, OVERLAY_LOOSE);
	add_win_loose_overlays(g, b);
}

void	add_enemy_to_coordinates(t_game_data *g, t_bonus *b, int x, int y)
{
	tile_win(g, b->enemy_sprite, x * g->tilesiz, y * g->tilesiz);
	b->enemy[b->total_enemies].x = x;
	b->enemy[b->total_enemies].y = y;
	b->total_enemies++;
	if (b->total_enemies >= 500)
		return (warning_too_many_enemies());
}

void	add_space_to_coordinates(t_game_data *g, t_bonus *b, int x, int y)
{
	tile_win(g, b->space_1, x * g->tilesiz, y * g->tilesiz);
	tile_win(g, b->space_2, x * g->tilesiz, y * g->tilesiz);
	tile_win(g, b->space_3, x * g->tilesiz, y * g->tilesiz);
}

void	add_game_tile_bonus(t_game_data *g, int x, int y, char c)
{
	t_bonus	*b;

	b = (t_bonus *)g->bonus;
	if (found_in_str(c, NON_WALL_CHARS))
		add_space_to_coordinates(g, b, x, y);
	if (found_in_str(c, ENEMY_CHARS))
	{
		add_enemy_to_coordinates(g, b, x, y);
		g->ber[y][x] = '0';
	}

}

void	z_position_tiles_bonus(t_game_data *g)
{
	t_bonus	*b;
	size_t	i;

	b = (t_bonus *)g->bonus;
	i = 0;
	while (i < b->space_1->count)
		mlx_set_instance_depth(&b->space_1->instances[i++], Z_SPACE);
	i = 0;
	while (i < b->space_2->count)
		mlx_set_instance_depth(&b->space_2->instances[i++], Z_SPACE);
	i = 0;
	while (i < b->space_3->count)
		mlx_set_instance_depth(&b->space_3->instances[i++], Z_SPACE);
	i = 0;
	while (i < b->enemy_sprite->count)
		mlx_set_instance_depth(&b->enemy_sprite->instances[i++], Z_ENEMY);
	if (b->text_image && b->text_image->count > 0)
		mlx_set_instance_depth(&b->text_image->instances[0], Z_MESSAGES);
	b->space_1->enabled = false;
	b->space_2->enabled = false;
	b->space_3->enabled = false;
}

void	check_chars_bonus(t_game_data *g)
{
	g->item.valid_chars = VALID_MAP_CHARS_BONUS;
}

void	clear_buf_bonus(t_bonus *b)
{
	ft_bzero(b->buf, BONUS_BUFFER_SIZE);
	b->buf_end = 0;
}

void	record_item_positions(t_game_data *g)
{
	t_bonus	*b;
	size_t	i;

	b = (t_bonus *)g->bonus;
	i = 0;
	while (i < g->item.total_collect)
	{
		b->collect_point[i].x = g->tile.collect[i]->instances[0].x;
		b->collect_point[i].y = g->tile.collect[i]->instances[0].y;
		i++;
	}
	b->exit_point.x = g->tile.exit_open->instances[0].x;
	b->exit_point.y = g->tile.exit_open->instances[0].y;
}

void	add_to_buf_bonus(t_bonus *b, char *str)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	if ((len + b->buf_end + 1) > BONUS_BUFFER_SIZE)
		return (clear_buf_bonus(b));
	i = 0;
	while (i < len)
	{
		b->buf[i + b->buf_end] = str[i];
		i++;
	}
	b->buf_end += len;
}

void	print_buf_bonus(t_game_data *g, t_bonus *b)
{
	put_str_bonus(g, b);
	clear_buf_bonus(b);
}

void	put_str_bonus(t_game_data *g, t_bonus *b)
{
	if (b->text_image)
		mlx_delete_image(g->mlx, b->text_image);
	b->text_image = mlx_put_string(g->mlx, b->buf, 10, 10);
	if (!b->text_image)
		exit_mlx_error(g, true);
}

void 	exit_game_reached_bonus(t_game_data *g)
{
	((t_bonus *)g->bonus)->remove_exit = true;
}

