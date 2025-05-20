/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:32 by tda-roch          #+#    #+#             */
/*   Updated: 2025/04/25 15:14:55 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the string ’s’ to the given file descriptor followed by a newline.
*/
void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	if (write(fd, "\n", 1))
		return ;
}

// int	main(void)
// {
// 	char *result = "abc def JKL MNO";
// 	ft_putendl_fd(result, 1);
// 	return (0);
// }