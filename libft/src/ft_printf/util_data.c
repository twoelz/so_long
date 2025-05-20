/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:58 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/07 11:32:16 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	b_zero(void *s, size_t n)
{
	t_uchar	*new_s;

	new_s = (t_uchar *)s;
	while (n--)
		*new_s++ = 0;
}

/*strlen alternative: loop unrolling by 4 bits*/
size_t	str_len(const char *str)
{
	const char	*s = str;

	while (s[0] && s[1] && s[2] && s[3])
		s += 4;
	while (*s)
		s++;
	return (s - str);
}

bool	c_in_str(t_uchar c, const char *s)
{
	while (*s)
	{
		if (*s == c)
			return (true);
		s++;
	}
	return (false);
}

/*isdigit alternative: takes unsigned char, returns bool*/
bool	is_digit(t_uchar c)
{
	return (c >= '0' && c <= '9');
}
