/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:55:04 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/15 17:21:19 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
returns 1 if char value fits into the ASCII character set (0-127). 0 if not.
____________
man isascii: checks whether c is a 7-bit unsigned char value that fits into 
the ASCII character set.
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
// #include <stdio.h>
// int main(void)
// {
// 	char t1 = 'A';
// 	int t2 = 128;
// 	int t3 = 10;
// 	int t4 = -10;
// 	printf("t1 is %d\nt2 is %d\nt3 is %d\nt4 is %d\n", t1, t2, t3, t4);
// 	printf("result of ft_isascii(t1) is %d \n", ft_isascii(t1));
// 	printf("result of ft_isascii(t2) is %d \n", ft_isascii(t2));
// 	printf("result of ft_isascii(t3) is %d \n", ft_isascii(t3));
// 	printf("result of ft_isascii(t4) is %d \n", ft_isascii(t4));
// }
