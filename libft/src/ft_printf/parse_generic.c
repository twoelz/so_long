/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_generic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 01:02:51 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/11 16:57:18 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_argument(t_pdata *data)
{
	const char	*s_copy;

	data->s++;
	s_copy = data->s;
	if (c_in_str(*data->s, FLAGS))
		parse_flags(data);
	if (is_digit(*data->s))
		parse_width(data);
	if (*data->s == precision)
		parse_precision(data);
	if (c_in_str(*data->s, SPECIFIERS))
		print_arg(data);
	else
	{
		add_c_buf(data, sentinel);
		data->s = s_copy;
		return ;
	}
	data->s++;
}

void	parse_width(t_pdata *data)
{
	data->fmt.width = parse_number(data);
}

size_t	parse_number(t_pdata *data)
{
	char	num_buf[MAX_INT_DIGITS];
	size_t	i;

	if (!is_digit(*data->s))
		return (0);
	i = 0;
	while (is_digit(*data->s))
	{
		num_buf[i++] = *data->s++;
		if (i == MAX_INT_DIGITS)
			break ;
	}
	num_buf[i] = '\0';
	return (nbuf_tosize(num_buf));
}
