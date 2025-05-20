/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:34:23 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/18 12:15:44 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns a pointer to the first occurrence of the
character c in the string s.
Returns:
	a pointer  to  the  matched character or 
	NULL if the character is not found. 
The terminating null byte is considered part of the string, so that if c 
is specified as '\0', these functions return a pointer to the terminator.
*/
char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("%s\n", ft_strchr("teste", 'e' + 256));
// 	printf("%s\n", strchr("teste", 'e' + 256));
// 	return (0);
// }
