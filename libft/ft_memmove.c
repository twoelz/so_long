/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:21:57 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/17 14:06:57 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
memmove copies n bytes from memory area src to memory area dest.  The memory 
areas may overlap. (original copies to temporary, this implementation just 
makes sure it wont overwrite)
RETURN VALUE
       The memmove() function returns a pointer to dest.
*/
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tsrc;
	unsigned char	*tdst;

	if (dst == src)
		return (dst);
	tsrc = (unsigned char *)src;
	tdst = (unsigned char *)dst;
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			tdst[i] = tsrc[i];
			i++;
		}
	}
	else
	{
		while (n--)
			tdst[n] = tsrc[n];
	}
	return (dst);
}
