/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:00 by tda-roch          #+#    #+#             */
/*   Updated: 2025/04/25 15:21:16 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the integer ’n’ to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	int	remainder;
	int	written;

	if (n == -2147483648)
		written = write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			written = write(fd, "-", 1);
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		remainder = (n % 10) + '0';
		written = write(fd, &remainder, 1);
	}
	(void)written;
}

// int	main(void)
// {
// 	ft_putnbr_fd(0, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(10, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(101, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(10000, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-4, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(5, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(14, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-25, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(342, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-12342, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(234239, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(2147483647, 1);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-2147483648, 1);
// 	write(1, "\n", 1);
// }
