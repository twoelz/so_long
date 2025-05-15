/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:00:06 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/15 17:24:43 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
returns 1 if the char given as a parameter contains a digit (char '0' to '9')
and 0 if it contains any other character
_____________
man description for isdigit: checks for a digit (0 through 9).
*/
int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char t1 = 'A';
// 	char t2 = '0';
// 	char t3 = '1';
// 	char t4 = '9';
// 	int t5 = -65;
// 	printf("t1 is %d\nt2 is %d\nt3 is %d\nt4 is %d\nt5 is %d\n", 
//  t1, t2, t3, t4, t5);
// 	printf("result of ft_isdigit(t1) is %d \n", ft_isdigit(t1));
// 	printf("result of ft_isdigit(t2) is %d \n", ft_isdigit(t2));
// 	printf("result of ft_isdigit(t3) is %d \n", ft_isdigit(t3));
// 	printf("result of ft_isdigit(t4) is %d \n", ft_isdigit(t4));
// 	printf("result of ft_isdigit(t5) is %d \n", ft_isdigit(t5));
// }