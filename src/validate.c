/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:38:05 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/18 18:39:03 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_extension(char *map_path, int *error_code)
{
	size_t	len;

	len = ft_strlen(map_path);
	if (len < 4 || \
			map_path[len - 4] != '.' || \
			map_path[len - 3] != 'b' || \
			map_path[len - 2] != 'e' || \
			map_path[len - 1] != 'r')
		*error_code = MAP_INVALID_EXTENSION;
	return (*error_code);
}

int	validate_path(char *map_path, int *error_code)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		*error_code = MAP_INVALID_PATH;
	else
		close(fd);
	return (*error_code);
}

int	validate_map(t_game_data *g, char *map_path)
{
	if (validate_extension(map_path, &g->error_code))
		return (g->error_code);
	if (validate_path(map_path, &g->error_code))
		return (g->error_code);
	ft_putnbr_fd(g->moves, STDOUT_FILENO);
	return (g->error_code);
}