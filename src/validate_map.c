/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:39:05 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 20:48:20 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
TODO: check if I need to free line after assigning the line to g->ber[i]
TODO: remove prints
*/
int	load_ber(t_game_data *g)
{
	int		fd;
	char	*line;
	int		i;

	g->ber = ft_calloc((g->height + 1), sizeof(char *));
	if (!g->ber)
		return (set_error_code(g, E_ALLOC));
	fd = open(g->ber_path, O_RDONLY);
	if (fd == -1)
		return (set_error_code(g, E_READ_ERROR));
	i = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\0' && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		g->ber[i] = line;
		i++;
	}
	print_ber(g);
	return (g->error_code);
}

int	check_rectangular(t_game_data *g)
{
	int	y;

	y = 0;
	while (y < g->height)
	{
		if ((int)ft_strlen(g->ber[y]) != g->width)
			return (set_error_code(g, E_NO_RECTANGLE));
		y++;
	}
	return (g->error_code);
}

int	check_chars(t_game_data *g)
{
	t_point	p;

	ft_bzero(&p, sizeof(p));
	while (p.y < g->height)
	{
		if (!found_in_str(g->ber[p.y][p.x], VALID_MAP_CHARS))
			return (set_error_code(g, E_INVALID_CHAR));
		next_point(&p, g->width);
	}
	return (g->error_code);
}

int	check_walled(t_game_data *g)
{
	t_point	p;

	ft_bzero(&p, sizeof(p));
	while (p.y < g->height)
	{
		if (((p.x == 0 || p.x == g->width - 1 \
				|| p.y == 0 || p.y == g->height - 1) \
				&& g->ber[p.y][p.x] != '1'))
			return (set_error_code(g, E_NO_WALLED));
		next_point(&p, g->width);
	}
	return (g->error_code);
}


int	validate_map(t_game_data *g)
{
	if (check_extension(g->ber_path, &g->error_code))
		return (g->error_code);
	if (check_path(g->ber_path, &g->error_code))
		return (g->error_code);
	if (check_minumum_size(g))
		return (g->error_code);
	if (load_ber(g))
		return (g->error_code);
	if (check_rectangular(g))
		return (g->error_code);
	if (check_chars(g))
		return (g->error_code);
	if (check_walled(g))
		return (g->error_code);
	return (g->error_code);
}

int	check_minumum_size(t_game_data *g)
{
	int		fd;
	char	*line;

	fd = open(g->ber_path, O_RDONLY);
	if (fd == -1)
		return (set_error_code(g, E_READ_ERROR));
	line = get_next_line(fd);
	if (!line)
		return (set_error_code(g, E_MINIMUM_SIZE));
	g->width = ft_strlen_exclude_newline(line);
	g->height = 1;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		g->height++;
		free(line);
	}
	if ((g->height < 3 || g->width < 3) || \
			g->height + g->width < 8)
		return (set_error_code(g, E_MINIMUM_SIZE));
	print_dimensions(g);
	return (g->error_code);
}
