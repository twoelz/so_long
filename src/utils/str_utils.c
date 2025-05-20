/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 03:04:06 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 03:04:26 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
gets a char to be found and a string.
returns 1 if found.
if not found, returns (0)
*/
int	found_in_str(char c_to_find, char *str)
{
	int	c_index;

	c_index = 0;
	while (str[c_index] != '\0')
	{
		if (str[c_index] == c_to_find)
			return (1);
		c_index++;
	}
	return (0);
}