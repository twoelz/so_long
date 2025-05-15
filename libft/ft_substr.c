/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:18:24 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/18 12:08:29 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Allocates (with malloc and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
*/
char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*result_str;

	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (s_len < start)
		len = 0;
	result_str = malloc((len + 1) * sizeof(char));
	if (!result_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result_str[i] = s[start + i];
		i++;
	}
	result_str[i] = '\0';
	return (result_str);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *longstring = "very super duper loooooooooong string";
// 	char *a_substring;

// 	a_substring = ft_substr(longstring, 7, 15);
// 	printf("%s\n", a_substring);
// }