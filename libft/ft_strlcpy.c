/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:26:05 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/16 13:11:02 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stddef.h>

/*
strlcpy takes the destination's size as a parameter and will not write more than
that many bytes, to prevent buffer overflow (assuming size is correct).
But, unlike strncpy, strlcpy always writes a single NUL byte to the destination
(if size is not zero). The resulting string is guaranteed to be NUL-terminated
even if truncated. Also it does not waste time writing multiple NUL bytes to
fill the rest of the buffer, unlike strncpy.
*/
size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (!size)
		return (src_size);
	i = 0;
	while (i < (size - 1) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}

// int	main(void)
// {
// 	#include <stdio.h>
// 	char	hello[] = "helloworld";
// 	char	dream[] = "dreamd";
// 	unsigned int	bread;
// 	printf("size of dream is %zu\n", sizeof(dream));
// 	printf("size of hello is %zu\n", sizeof(hello));
// 	printf("dream is %s\n", dream);
// 	printf("hello is %s\n", hello);
// 	bread = ft_strlcpy(dream, hello, sizeof(dream)); //10 + 1 for the NUL
// 	printf("dream is %s\n", dream);
// 	printf("hello is %s\n", hello);
// 	printf("bread is %d\n", bread);
// 	printf("size of dream is %zu\n", sizeof(dream));
// 	printf("size of hello is %zu\n", sizeof(hello));
// }