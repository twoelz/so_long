/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:24:32 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/11 14:25:11 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_buf(t_pdata *data)
{
	write(1, data->buf, data->buf_i);
	initialize_buf(data);
}

void	add_c_buf(t_pdata *data, const char c)
{
	if (data->buf_i > BUFFER_SIZE - 10)
		print_buf(data);
	data->buf[data->buf_i++] = c;
	data->printed_chars++;
}

void	add_str_buf(t_pdata *data, const char *str)
{
	while (*str)
		add_c_buf(data, *str++);
}
