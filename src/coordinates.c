/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:15:38 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 19:22:36 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Given a point (x/y coordinate struct) and a fixed width,
updates the pointer to the next coordinate.
Note1: this works for fixed-width coordinate maps only.
Note2: caller must check for map height (maximum y)
*/
void	next_point(t_point *p, int width)
{
	p->x++;
	if (p->x >= width)
	{
		p->x = 0;
		p->y++;
	}
}
