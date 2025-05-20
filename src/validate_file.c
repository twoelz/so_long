/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:38:05 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 21:01:17 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_empty(int fd, int *error_code)
{
	char	buffer;
	ssize_t	bytes_read;

	bytes_read = read(fd, &buffer, 1);
	if (bytes_read == 0)
		*error_code = E_FILE_EMPTY;
	else if (bytes_read < 0)
		*error_code = E_READ_ERROR;
	return (*error_code);
}

int	check_extension(char *ber_path, int *error_code)
{
	size_t	len;

	len = ft_strlen(ber_path);
	if (len < 4 || \
			ber_path[len - 4] != '.' || \
			ber_path[len - 3] != 'b' || \
			ber_path[len - 2] != 'e' || \
			ber_path[len - 1] != 'r')
		*error_code = E_INVALID_EXT;
	return (*error_code);
}

int	check_path(char *ber_path, int *error_code)
{
	int		fd;

	fd = open(ber_path, O_RDONLY);
	if (fd == -1)
	{
		*error_code = E_INVALID_PATH;
		return (*error_code);
	}
	*error_code = validate_empty(fd, error_code);
	close(fd);
	return (*error_code);
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
