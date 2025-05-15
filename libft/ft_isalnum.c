/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:20:56 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/15 17:24:58 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
returns 1 if the char given as a parameter contains an alphabetical character
or number digit. and 0 if it contains any other character
____________
man isalnum: checks for an alphanumeric character; it is equivalent to 
(isalpha(c) || isdigit(c)).
*/

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char t1 = 'A';
// 	char t2 = '=';
// 	int t3 = 10;
// 	char t4 = 'z';
// 	int t5 = -65;
// 	printf("t1 is %d\nt2 is %d\nt3 is %d\nt4 is %d\nt5 is %d\n", 
//  t1, t2, t3, t4, t5);
// 	printf("result of ft_isalnum(t1) is %d \n", ft_isalnum(t1));
// 	printf("result of ft_isalnum(t2) is %d \n", ft_isalnum(t2));
// 	printf("result of ft_isalnum(t3) is %d \n", ft_isalnum(t3));
// 	printf("result of ft_isalnum(t4) is %d \n", ft_isalnum(t4));
// 	printf("result of ft_isalnum(t5) is %d \n", ft_isalnum(t5));
// }
