/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:45:21 by tda-roch          #+#    #+#             */
/*   Updated: 2025/06/04 01:48:37 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
fills the first n bytes of the memory area pointed to by s
with the constant byte c.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*new_s;

	new_s = (unsigned char *)s;
	while (n--)
		*new_s++ = (unsigned char)c;
	return (s);
}
