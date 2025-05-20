/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:30:57 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/18 01:34:37 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies  n bytes from memory area src to memory
area dest.  The memory areas must not overlap.  Use memmove if the
memory areas do overlap.
RETURN VALUE
	The memcpy() function returns a pointer to dest.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*uc_src;
	unsigned char	*uc_dst;

	uc_src = (unsigned char *)src;
	uc_dst = (unsigned char *)dst;
	if (uc_src == uc_dst)
		return (dst);
	i = 0;
	while (i < n)
	{
		uc_dst[i] = uc_src[i];
		i++;
	}
	return (dst);
}
