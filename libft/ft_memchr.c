/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:41:50 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/18 02:00:03 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
scans  the  initial n bytes of the memory area
pointed to by s for the first instance of c.  Both c and the bytes  of
the memory area pointed to by s are interpreted as unsigned char.

RETURN VALUE
	return a pointer to  the  matching byte or NULL if the character
	does not occur in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*us;

	uc = (unsigned char)c;
	us = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*us == uc)
			return ((void *)us);
		us++;
		i++;
	}
	return (NULL);
}
