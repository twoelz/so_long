/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:15:54 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/17 22:14:04 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
counts and returns the number of characters in a string
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char test1[] = "short";
// 	char test2[] = "very very very long";
// 	char test3[] = "";
// 	printf("test1 is %s, lenght is %zu\n", test1, ft_strlen(test1));
// 	printf("test2 is %s, lenght is %zu\n", test2, ft_strlen(test2));
// 	printf("test3 is %s, lenght is %zu\n", test3, ft_strlen(test3));
// }
