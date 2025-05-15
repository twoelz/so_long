/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 00:31:05 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/18 12:02:25 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
erases the data in the n bytes of the memory starting at the
location pointed to by s, by writing zeros (bytes containing '\0') to that area.
RETURN VALUE: None.
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char	s[] = "0123456789";
// 	size_t	i = 0;
// 	size_t	len_s = strlen(s);

// 	printf("s before is:\n");
// 	while (i++ < len_s)
// 		printf("%c\n", s[i]);
// 	i = 0;
// 	ft_bzero(s, len_s);
// 	printf("s after is:\n");
// 	while (i++ < len_s)
// 		printf("%c\n", s[i]);
// }
