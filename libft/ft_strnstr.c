/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:24:01 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/18 11:57:27 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
locates the first occurrence of the null-terminated string little in the 
string big, where not more than len characters are searched.  Characters that
appear after a ‘\0’ character are not searched.
RETURN VALUES
	If little is an empty string, big is returned; if little occurs nowhere
	in big, NULL is returned; otherwise a pointer to the first character of
	the first occurrence of little is returned.
EXAMPLES
    The following sets the pointer ptr to NULL, because only the first 4
    characters of largestring are searched:
        const char *largestring = "Foo Bar Baz";
        const char *smallstring = "Bar";
        char *ptr;
        ptr = strnstr(largestring, smallstring, 4);
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	if (!(*little))
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] == little[j] && little[j] != '\0' && i + j < len)
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <stdlib.h>
// int main (void)
// {
// 	char *small;
// 	char str[] = "\ngood morning,\ngood evening\ngood night!";
// 	char to_find[] = "vening";
// 	char *place_in_str;
// 	char *place_in_str2;
// 	char *stdc_place_in_str;
// 	small = NULL;
// 	printf("hello1\n");
// 	place_in_str = ft_strnstr(((void*)0), to_find, 0);
// 	printf("hello2\n");
// 	printf("%s\n", place_in_str);
// 	printf("hello3\n");
// }
