/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:22:56 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 13:21:48 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the character ’c’ to stdout.
*/
void	ft_putchar(char c)
{
	if (write(STDOUT_FILENO, &c, 1))
		return ;
}
