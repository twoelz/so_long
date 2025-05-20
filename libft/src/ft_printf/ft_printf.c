/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:59:42 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/11 14:24:50 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_pdata		data;
	char		buf[BUFFER_SIZE];

	if (s == NULL)
		return (-1);
	va_start(data.ap, s);
	init_pdata(&data, s, buf);
	while (*data.s)
	{
		if (*data.s == sentinel)
			parse_argument(&data);
		else
			print_sub_s(&data);
	}
	va_end(data.ap);
	print_buf(&data);
	return (data.printed_chars);
}
