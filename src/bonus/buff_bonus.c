/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:48:19 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 14:49:03 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	clear_buf_bonus(t_bonus *b)
{
	ft_bzero(b->buf, BONUS_BUFFER_SIZE);
	b->buf_end = 0;
}

void	put_str_bonus(t_game_data *g, t_bonus *b)
{
	if (b->text_image)
		mlx_delete_image(g->mlx, b->text_image);
	b->text_image = mlx_put_string(g->mlx, b->buf, 10, 10);
	if (!b->text_image)
		exit_mlx_error(g, true);
}

void	print_buf_bonus(t_game_data *g, t_bonus *b)
{
	put_str_bonus(g, b);
	clear_buf_bonus(b);
}
