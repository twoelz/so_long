/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:47:32 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 13:21:52 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Outputs the string ’s’ to stdout followed by a newline.
*/
void	ft_putendl(char const *s)
{
	ft_putstr(s);
	if (write(STDOUT_FILENO, "\n", 1))
		return ;
}
