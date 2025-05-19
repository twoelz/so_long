/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:39:05 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/19 15:35:09 by tda-roch         ###   ########.fr       */
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

//TODO: delete print dimensions
void	print_ber(t_game_data *g)
{
	int	y;

	y = 0;
	while (y < g->height)
	{
		ft_putstr_fd(g->ber[y], STDOUT_FILENO);
		y++;
	}
}
/*
TODO: check if I need to free line after assigning the line to g->ber[i]
*/
int	load_ber(t_game_data *g)
{
	int		fd;
	char	*line;
	int		i;

	g->ber = malloc(g->height * sizeof(char *));
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
		g->ber[i] = line;
		i++;
	}
	printf("loaded ber\n");
	print_ber(g);
	if (g->ber[g->height - 1][ft_strlen(g->ber[g->height - 1]) - 1] != '\n')
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (g->error_code);
}

int	validate_map(t_game_data *g)
{
	if (validate_extension(g->ber_path, &g->error_code))
		return (g->error_code);
	if (validate_path(g->ber_path, &g->error_code))
		return (g->error_code);
	if (validate_minumum_size(g))
		return (g->error_code);
	if (load_ber(g))
		return (g->error_code);
	return (g->error_code);
}


/*
counts and returns the number of characters in a string excluding newlines
*/
size_t	ft_strlen_exclude_newline(const char *str)
{
	size_t	i;
	size_t	exclude_nl_len;

	i = 0;
	exclude_nl_len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			exclude_nl_len++;
		i++;
	}

	return (exclude_nl_len);
}

int	validate_minumum_size(t_game_data *g)
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
