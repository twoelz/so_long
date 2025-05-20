/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:15:53 by tda-roch          #+#    #+#             */
/*   Updated: 2025/04/25 22:13:48 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
allocates memory for an array of nmemb elements of size bytes each and returns a
pointer to the allocated memory.  The memory is set to zero.
If nmemb or size is 0, then calloc() returns a unique pointer value that can
later be successfully passed to free().

If the multiplication of nmemb and size would result in integer overflow, then
calloc() returns an error.
By contrast, an integer overflow would not be detected in the following call to
malloc(), with the result that an incorrectly sized block of memory would be 
allocated.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (nmemb * size));
	return (p);
}
// #include <stdio.h>
// int main() {
//     int *arr = ft_calloc(10, sizeof(int));
// 	size_t	i = 0;
//     while (i < 10) 
// 	{
//         if (arr[i] != 0)
// 			printf("error");
// 		i++;
//     }
//     free(arr);
//     return 0;
// }
