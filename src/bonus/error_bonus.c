/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 02:19:18 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/06 16:47:03 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
Not a critical error, just a warning, so the game does not exit.
Enemy just don't get added and warning is printed in terminal.
*/
void	warning_too_many_enemies(void)
{
	ft_putendl(E_TOO_MANY_ENEMIES_MSG);
}
