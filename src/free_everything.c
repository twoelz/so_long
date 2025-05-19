/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 23:33:11 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 00:30:31 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	safe_free_int(int **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	safe_free_char(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	safe_free_2d_char(char ***ptr)
{
	size_t	i;

	printf("will try to free\n");
	if (ptr && *ptr)
	{
		i = 0;
		printf("0\n");
		while ((*ptr)[i])
		{
			safe_free_char(&(*ptr)[i]);
			i++;
			printf("%ld\n", i);
		}
		free(*ptr);
		*ptr = NULL;
	}
	printf("free!\n");
}

void	free_everything(t_game_data *g)
{
	safe_free_2d_char(&g->ber);
}
