/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:33:43 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/17 22:14:49 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Converts the initial portion of the string pointed by str to its int
representation.
The string can start with an arbitray amount of white space.
The string can be followed by one + or - sign,
sign will change the sign of the int returned
The string can be followed by any numbers of the base 10.
Function should read the string until the string stop following the
rules and return the number found until now.
no overflow or underflow is handled. result can be undefined in that case.
Example:
$>./a.out " -1234ab567"
-1234
*/
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
	{
		result = result * 10 + (*nptr - '0');
		nptr ++;
	}
	return (result * sign);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_atoi(" ---+--+1234ab567"));
// 	printf("%d\n", ft_atoi(" +1234ab567"));
// 	printf("%d\n", ft_atoi("\t\n\r\v\f  469 \n"));
// }
