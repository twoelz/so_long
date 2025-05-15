/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:33:51 by tda-roch          #+#    #+#             */
/*   Updated: 2025/04/25 15:25:16 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the string ’s’ to the given file descriptor.
*/
void	ft_putstr_fd(char const *s, int fd)
{
	int	written;

	while (*s != '\0')
	{
		written = write(fd, s, 1);
		s++;
	}
	(void)written;
}

// int	main(void)
// {
// 	char *result = "abc def JKL MNO\n";
// 	ft_putstr_fd(result, 1);
// 	return (0);
// }
