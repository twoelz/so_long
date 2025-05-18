/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:36:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/19 01:15:07 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_error_code(t_game_data *g, char *error_code)
{
	g->error_code = error_code;
	return (error_code);
}

//TODO: change error message according to error code (if needed)
int	return_error(int error_code)
{
	ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	if (error_code == MAP_NO_PATH_ARGUMENT)
		ft_putstr_fd(MAP_NO_PATH_ARGUMENT_MSG, STDERR_FILENO);
	else if (error_code == MAP_INVALID_EXTENSION)
		ft_putstr_fd(MAP_INVALID_EXTENSION_MSG, STDERR_FILENO);
	else if (error_code == MAP_INVALID_PATH)
		ft_putstr_fd(MAP_INVALID_PATH_MSG, STDERR_FILENO);
	return (error_code);
}

// TODO: REMOVE fprintf and see if printing those errors are needed
void	exit_after_mlx_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
