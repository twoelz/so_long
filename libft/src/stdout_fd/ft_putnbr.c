/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:58:00 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 13:21:55 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the integer ’n’ to stdout.
*/
void	ft_putnbr(int n)
{
	int	remainder;
	int	written;

	if (n == -2147483648)
		written = write(STDOUT_FILENO, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n = -n;
			written = write(STDOUT_FILENO, "-", 1);
		}
		if (n >= 10)
			ft_putnbr(n / 10);
		remainder = (n % 10) + '0';
		written = write(STDOUT_FILENO, &remainder, 1);
	}
	(void)written;
}
