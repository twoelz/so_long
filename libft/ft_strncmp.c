/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:03:45 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/16 13:09:35 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
compares the two strings s1 and s2.
similar to ft_strcmp() it also returns an integer indicating the result of the 
comparison. but it compares only the first (at most) n bytes of s1 and s2.
*/
int	ft_strncmp(char const *s1, char const*s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(unsigned char *)s1 || *(unsigned char *)s2) && (n > i))
	{
		if (*(unsigned char *)s1 - *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char s1[] = "ABCDZ";
// 	char s2[] = "ABCDAZ";
// 	printf("s1 is %s\ns2 is %s\n", s1, s2);
// 	printf("result of ft_strncmp(s1, s2, 0) is %d \n", ft_strncmp(s1, s2, 0));
// 	printf("result of ft_strncmp(s1, s2, 1) is %d \n", ft_strncmp(s1, s2, 1));
// 	printf("result of ft_strncmp(s1, s2, 2) is %d \n", ft_strncmp(s1, s2, 2));
// 	printf("result of ft_strncmp(s1, s2, 3) is %d \n", ft_strncmp(s1, s2, 3));
// 	printf("result of ft_strncmp(s1, s2, 4) is %d \n", ft_strncmp(s1, s2, 4));
// 	printf("result of ft_strncmp(s1, s2, 5) is %d \n", ft_strncmp(s1, s2, 5));
// 	printf("result of ft_strncmp(s1, s2, 6) is %d \n", ft_strncmp(s1, s2, 6));
// 	printf("result of ft_strncmp(s1, s2, 7) is %d \n", ft_strncmp(s1, s2, 7));
// }