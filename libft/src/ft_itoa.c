/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:54 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/16 14:50:44 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static unsigned int	get_abs(int n)
{
	if (n < 0)
		return ((unsigned int)(-n));
	return ((unsigned int)(n));
}

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
*/
char	*ft_itoa(int n)
{
	int				sign;
	int				digits;
	char			*res;
	unsigned int	abs_n;

	sign = 0;
	abs_n = get_abs(n);
	if (n < 0)
		sign = 1;
	digits = count_digits(abs_n);
	res = malloc((digits + sign + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[digits + sign] = '\0';
	while (digits > 0)
	{
		res[--digits + sign] = (abs_n % 10) + '0';
		abs_n /= 10;
	}
	if (sign)
		res[0] = '-';
	return (res);
}
// #include <stdio.h>
// int main(void)
// {
// 	int n1 = -2147483648;
// 	int n2 = 2147483647;
// 	int n3 = 0;
// 	int n4 = -1;
// 	int n5 = 1;
// 	int n6 = 12345607;
// 	int n7 = -98700654;
// 	int n8 = 3030;
// 	int n9 = -5000;

// 	printf("%s\n", ft_itoa(n1));
// 	printf("%s\n", ft_itoa(n2));
// 	printf("%s\n", ft_itoa(n3));
// 	printf("%s\n", ft_itoa(n4));
// 	printf("%s\n", ft_itoa(n5));
// 	printf("%s\n", ft_itoa(n6));
// 	printf("%s\n", ft_itoa(n7));
// 	printf("%s\n", ft_itoa(n8));
// 	printf("%s\n", ft_itoa(n9));
// }
