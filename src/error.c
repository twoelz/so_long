/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:36:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/18 17:53:36 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	exit_after_mlx_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
