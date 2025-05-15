/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:05:28 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/15 17:25:28 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
returns 1 if char value is an ASCII printable character including space 
(32 to 126). 0 if not.
____________
man isprint: checks for any printable character including space.
.
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// #include <stdio.h>
// int main(void)
// {
// 	char t1 = 'A';
// 	int t2 = 128;
// 	int t3 = 125;
// 	int t4 = -10;
// 	int t5 = -65;
// 	char t6 = ' ';
// 	printf("t1 is %d\nt2 is %d\nt3 is %d\nt4 is %d\nt5 is %d\nt6 is %d\n", 
// 		t1, t2, t3, t4, t5, t6);
// 	printf("result of ft_isprint(t1) is %d \n", ft_isprint(t1));
// 	printf("result of ft_isprint(t2) is %d \n", ft_isprint(t2));
// 	printf("result of ft_isprint(t3) is %d \n", ft_isprint(t3));
// 	printf("result of ft_isprint(t4) is %d \n", ft_isprint(t4));
// 	printf("result of ft_isprint(t5) is %d \n", ft_isprint(t5));
// 	printf("result of ft_isprint(t6) is %d \n", ft_isprint(t6));
// }