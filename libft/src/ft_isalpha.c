/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:52:25 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/15 17:23:56 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
returns 1 if the char given as a parameter contains an alphabetical character
and 0 if it contains any other character
_____________
man description for isalpha: checks for an alphabetic character; in the standard
"C" locale, it is equivalent to (isupper(c)  ||  islower(c)).
*/
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char t1 = 'A';
// 	char t2 = '=';
// 	char t3 = '1';
// 	char t4 = 'z';
// 	int t5 = -65;
// 	printf("t1 is %d\nt2 is %d\nt3 is %d\nt4 is %d\nt5 is %d\n",
//		 t1, t2, t3, t4, t5);
// 	printf("result of ft_isalpha(t1) is %d \n", ft_isalpha(t1));
// 	printf("result of ft_isalpha(t2) is %d \n", ft_isalpha(t2));
// 	printf("result of ft_isalpha(t3) is %d \n", ft_isalpha(t3));
// 	printf("result of ft_isalpha(t4) is %d \n", ft_isalpha(t4));
// 	printf("result of ft_isalpha(t5) is %d \n", ft_isalpha(t5));
// }