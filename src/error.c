/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:36:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/19 12:45:28 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO: REMOVE fprintf and see if printing those errors are needed
void	exit_after_mlx_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	init_error_messages(t_game_data *g)
{
	set_error_message(g->error_message, E_SUCCESS, E_SUCCESS_MSG);
	set_error_message(g->error_message, E_NO_PATH_ARG, E_NO_PATH_ARG_MSG);
	set_error_message(g->error_message, E_INVALID_EXT, E_INVALID_EXT_MSG);
	set_error_message(g->error_message, E_INVALID_PATH, E_INVALID_PATH_MSG);
	set_error_message(g->error_message, E_FILE_EMPTY, E_FILE_EMPTY_MSG);
	set_error_message(g->error_message, E_READ_ERROR, E_READ_ERROR_MSG);
	set_error_message(g->error_message, E_MINIMUM_SIZE, E_MINIMUM_SIZE_MSG);
	set_error_message(g->error_message, E_INVALID_CHAR, E_INVALID_CHAR_MSG);
	set_error_message(g->error_message, E_NO_RECTANGLE, E_NO_RECTANGLE_MSG);
	set_error_message(g->error_message, E_NO_WALLED, E_NO_WALLED_MSG);
	set_error_message(g->error_message, E_NO_COLLECT, E_NO_COLLECT_MSG);
	set_error_message(g->error_message, E_NO_START, E_NO_START_MSG);
	set_error_message(g->error_message, E_NO_EXIT, E_NO_EXIT_MSG);
	set_error_message(g->error_message, E_MULTI_START, E_MULTI_START_MSG);
	set_error_message(g->error_message, E_MULTI_EXIT, E_MULTI_EXIT_MSG);
}

int	set_error_code(t_game_data *g, int error_code)
{
	g->error_code = error_code;
	return (error_code);
}

void	set_error_message(t_error_message *error_message, \
			int error_code, char *message)
{
	error_message[error_code].error_code = error_code;
	error_message[error_code].message = message;

}

//TODO: change error message according to error code (if needed)
int	return_error(t_game_data *g)
{
	ft_putstr_fd(ERROR_MSG, STDOUT_FILENO);
	ft_putstr_fd(g->error_message[g->error_code].message, STDOUT_FILENO);
	return (g->error_code);
}
