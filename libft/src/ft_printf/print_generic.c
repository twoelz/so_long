/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_generic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:33:19 by tda-roch          #+#    #+#             */
/*   Updated: 2024/11/09 09:46:39 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_arg(t_pdata *data)
{
	const char	specifier = *data->s;

	data->fmt.specifier = specifier;
	if (specifier == sentinel)
		print_arg_sentinel(data);
	else if (specifier == 'c')
		print_arg_c(data);
	else if (c_in_str(specifier, "sp"))
		print_strdata(data);
	else if (c_in_str(specifier, "diuxX"))
		print_numdata(data);
	initialize_fmt(data);
}

void	print_arg_sentinel(t_pdata *data)
{
	add_c_buf(data, sentinel);
	print_buf(data);
}

void	print_sub_s(t_pdata *data)
{
	while (*data->s && *data->s != sentinel)
		add_c_buf(data, *data->s++);
}
