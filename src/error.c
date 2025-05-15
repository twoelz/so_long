/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:36:42 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/15 12:47:36 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//TODO: remove fprintf -- add ft_printf into libft and replace here
void	exit_after_mlx_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
