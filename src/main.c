/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:57:46 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/03 20:20:33 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
runs the MANDATORY version of the so_long project (instead of BONUS version)
	so_long is a simple game where you need to collect all collectible items
	then reach the exit, with the minimal amount of moves.
*/
int	main(int argc, char **argv)
{
	bool	is_bonus;

	is_bonus = false;
	return (so_long(argc, argv, is_bonus));
}
