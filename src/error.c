/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:36:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/19 02:08:24 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_error_code(t_game_data *g, int error_code)
{
	g->error_code = error_code;
	return (error_code);
}

//TODO: change error message according to error code (if needed)
int	return_error(int error_code)
{
	ft_putstr_fd(ERROR_MSG, STDOUT_FILENO);
	if (error_code == MAP_NO_PATH_ARGUMENT)
		ft_putstr_fd(MAP_NO_PATH_ARGUMENT_MSG, STDOUT_FILENO);
	else if (error_code == MAP_INVALID_EXTENSION)
		ft_putstr_fd(MAP_INVALID_EXTENSION_MSG, STDOUT_FILENO);
	else if (error_code == MAP_INVALID_PATH)
		ft_putstr_fd(MAP_INVALID_PATH_MSG, STDOUT_FILENO);
	else if (error_code == MAP_FILE_EMPTY)
		ft_putstr_fd(MAP_FILE_EMPTY_MSG, STDOUT_FILENO);
	else if (error_code == MAP_READ_ERROR)
		ft_putstr_fd(MAP_READ_ERROR_MSG, STDOUT_FILENO);
	else if (error_code == MAP_MINIMUM_SIZE)
		ft_putstr_fd(MAP_MINIMUM_SIZE_MSG, STDOUT_FILENO);
	else if (error_code == MAP_MULTIPLE_EXIT)
		ft_putstr_fd(MAP_MULTIPLE_EXIT_MSG, STDOUT_FILENO);
	else if (error_code == MAP_NO_EXIT)
		ft_putstr_fd(MAP_NO_EXIT_MSG, STDOUT_FILENO);
	else if (error_code == MAP_MULTIPLE_START)
		ft_putstr_fd(MAP_MULTIPLE_START_MSG, STDOUT_FILENO);
	else if (error_code == MAP_NO_START)
		ft_putstr_fd(MAP_NO_START_MSG, STDOUT_FILENO);
	else if (error_code == MAP_NO_COLLECTIBLE)
		ft_putstr_fd(MAP_NO_COLLECTIBLE_MSG, STDOUT_FILENO);
	else if (error_code == MAP_NO_RECTANGLE)
		ft_putstr_fd(MAP_NO_RECTANGLE_MSG, STDOUT_FILENO);
	else if (error_code == MAP_NO_WALLED)
		ft_putstr_fd(MAP_NO_WALLED_MSG, STDOUT_FILENO);
	return (error_code);
}

// TODO: REMOVE fprintf and see if printing those errors are needed
void	exit_after_mlx_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
