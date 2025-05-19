/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:39:05 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/19 12:36:49 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TODO: delete print dimensions
void	print_dimensions(t_game_data *g)
{
	ft_putstr_fd("width: ", STDOUT_FILENO);
	ft_putnbr_fd(g->width, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_putstr_fd("height: ", STDOUT_FILENO);
	ft_putnbr_fd(g->height, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

int	validate_map(t_game_data *g, char *map_path)
{
	if (validate_extension(map_path, &g->error_code))
		return (g->error_code);
	if (validate_path(map_path, &g->error_code))
		return (g->error_code);
	if (validate_map_dimensions(g, map_path))
		return (g->error_code);
	return (g->error_code);
}

//TODO: remove print dimensions
int	validate_map_dimensions(t_game_data *g, char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (set_error_code(g, E_READ_ERROR));
	line = get_next_line(fd);
	if (!line)
		return (set_error_code(g, E_MINIMUM_SIZE));
	g->width = strlen(line);
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
