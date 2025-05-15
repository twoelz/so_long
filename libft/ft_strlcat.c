/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:13:00 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/16 11:37:30 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stddef.h>

/*
designed to be safer, more consistent, and less error prone replacements for
strncat.  Unlike those functions, strlcat() take the full size of the buffer
(not just the length) and guarantee to NUL-terminate the result (as long as
size is larger than 0 or, in the case of strlcat(), as long as there is at
least one byte free in dst).  Note that a byte for the NUL should be included
in size.
This means that for strlcat() both src and dst must be NUL-terminated.
RETURN VALUES
The strlcat() function return the total length of the string they tried to
create. That means the initial length of dst plus the length of src. While
this may seem somewhat confusing, it was done to make truncation detection
simple.
Note, however, that if strlcat() traverses size characters without finding a
NUL, the length of the string is considered to be size and the destination
string will not be NUL-terminated (since there was no space for the NUL).
This keeps strlcat() from running off the end of a string. In practice this
should not happen (as it means that either size is incorrect or that dst is
not a proper “C” string).  The check exists to prevent potential security
problems in incorrect code.
*/
size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (dst_len < size && dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <stdio.h>
// int main(void)
// {
// 	unsigned int size;
// 	unsigned int result;
// 	size = 9;
// 	char s1[20] = "ABCDEF";
// 	char s2[] = "HJKLMN";
// 	printf("s1 is %s\ns2 is %s\nsize = %d\n", s1, s2, size);
// 	result = ft_strlcat(s1, s2, size);
// 	printf("return of ft_strncat(s1, s2, size) is %d\n", result);
// 	printf("s1 string after ft_strncat(s1, s2, size) is %s\n", s1);
// }
