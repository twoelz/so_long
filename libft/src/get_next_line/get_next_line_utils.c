/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:30:08 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/19 01:41:45 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*returns position in str.
	otherwise returns GNL_ERROR (-1)*/
ssize_t	newline_in_str(const char *s)
{
	const unsigned char	newline = '\n';
	const char			*ptr;

	if (!s)
		return (GNL_ERROR);
	ptr = s;
	while (*ptr && *ptr != newline)
		ptr++;
	if (*ptr == newline)
		return (ptr - s);
	return (GNL_ERROR);
}

/* return is always:
	-1 = GNL_ERROR */
int	free_strings(char **str1, char **str2)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
	return (GNL_ERROR);
}
