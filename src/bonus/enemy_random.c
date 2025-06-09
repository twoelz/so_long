/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_random.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 13:30:20 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/09 13:38:57 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
using coordinates:
	0 = right
	1 = left
	2 = top
	3 = down
*/
void	fill_move_coordinates(t_point arr[4])
{
	arr[0].x = 1;
	arr[0].y = 0;
	arr[1].x = -1;
	arr[1].y = 0;
	arr[2].x = 0;
	arr[2].y = -1;
	arr[3].x = 0;
	arr[3].y = 1;
}

void	fill_move_permutations(int arr[24][4])
{
	const char	*perm_string;
	int			i;
	int			j;

	perm_string = "213010320321321031022031120301232301312030120132"
		"102313200231231030211230210303122013021332011302";
	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 4)
		{
			arr[i][j] = perm_string[i * 4 + j] - '0';
			j++;
		}
		i++;
	}
}

int	get_random_int(int max_value, int offset)
{
	unsigned int	seed;
	int				result;

	seed = (unsigned int)(mlx_get_time() * 1000.0);
	result = ((seed * KNUTH) + offset) % max_value;
	return (result);
}
