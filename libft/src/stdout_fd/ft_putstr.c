/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:33:51 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 13:22:55 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the string ’s’ to stdout.
*/
void	ft_putstr(char const *s)
{
	int	written;

	while (*s != '\0')
	{
		written = write(STDOUT_FILENO, s, 1);
		s++;
	}
	(void)written;
}

