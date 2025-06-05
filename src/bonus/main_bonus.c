/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:57:46 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/05 14:16:43 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
runs the BONUS version of the so_long project (instead of MANDATORY version)
	so_long is a simple game where you need to collect all collectible items
	then reach the exit, with the minimal amount of moves.
	the bonus version adds some features to mandatory:
		- item/sprite animations
		- movement count shown directly on game screen instead of terminal
		- "enemy patrols" (placed using letters V, M or F in the ber file)
		(player looses game if enemy is touched)
*/
int	main(int argc, char **argv)
{
	bool	is_bonus;

	is_bonus = true;
	return (so_long(argc, argv, is_bonus));
}
