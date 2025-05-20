/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:04:06 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 20:03:38 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/*
takes a char to be found and a string.
returns true if found,
false if not
*/
bool	found_in_str(char c_to_find, char *str)
{
	int	c_index;

	c_index = 0;
	while (str[c_index] != '\0')
	{
		if (str[c_index] == c_to_find)
			return (true);
		c_index++;
	}
	return (false);
}
