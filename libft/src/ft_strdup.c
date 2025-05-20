/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:49:55 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/18 12:06:25 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Returns a pointer to a new string which is a duplicate of the string src.
Memory for the new string is obtained with malloc, and can be freed with free.
*/
char	*ft_strdup(char const *src)
{
	char	*new_src;
	int		i;

	i = 0;
	new_src = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!new_src)
		return (NULL);
	while (src[i] != '\0')
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}

// #include <unistd.h>
// int main(void)
// {
// 	char src[] = "hello world";
// 	char *copy;
// 	int i;
// 	char c;
// 	i = 0;
// 	copy = ft_strdup(src);
// 	while (copy[i] != '\0')
// 	{
// 		c = copy[i];
// 		write(1, &c, 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	free(copy);
// 	return (0);
// }
