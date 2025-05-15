/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 02:02:30 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/18 02:26:23 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
compares the first n bytes (each interpreted as
unsigned char) of the memory areas s1 and s2.
RETURN VALUE
	Returns  an  integer  less  than,  equal  to,  or
    greater than zero if the first n bytes of s1 is found, respectively, to
    be less than, to match, or be greater than the first n bytes of s2.
	For  a  nonzero return value, the sign is determined by the sign of the
    difference between the first pair of  bytes  (interpreted  as  unsigned
    char) that differ in s1 and s2.
	If n is zero, the return value is zero.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	if (!n || us1 == us2)
		return (0);
	i = 0;
	while (i < n)
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
