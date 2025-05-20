/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:22:56 by tda-roch          #+#    #+#             */
/*   Updated: 2025/04/25 15:13:38 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the character ’c’ to the given file descriptor.
*/
void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1))
		return ;
}

// int	main(void)
// {
// 	char *result = "abc def JKL MNO\n";
// 	while (*result != '\0')
// 	{
// 		ft_putchar_fd(*result, 1);
// 		result++;
// 	}
// 	return (0);
// }