/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:18:29 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/20 13:53:47 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
returns 1 if char passed if to be found in str passed.
otherwise, returns 0
*/
static int	char_in_str(char const c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_t_start(char const *s1, char const *set, size_t const slen)
{
	size_t	i;

	i = 0;
	while (i < slen && char_in_str(s1[i], set))
		i++;
	return (i);
}

static size_t	get_t_end(char const *s1, char const *set, size_t const slen)
{
	size_t	trim_end;
	size_t	i;

	trim_end = 0;
	if (!slen)
		return (trim_end);
	i = slen - 1;
	while (char_in_str(s1[i], set))
	{
		trim_end++;
		if (i)
			i--;
		else
			break ;
	}
	return (trim_end);
}

/*
Allocates (with malloc) and returns a copy of ’s1’ with the characters
specified in ’set’ removed from the beginning and the end of the string.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		slen;
	size_t		trim_start;
	size_t		trim_end;
	size_t		i;
	char		*trim_str;

	slen = ft_strlen(s1);
	trim_start = get_t_start(s1, set, slen);
	trim_end = 0;
	if (trim_start != slen)
		trim_end = get_t_end(s1, set, slen);
	trim_str = malloc((slen - trim_start - trim_end + 1) * sizeof(char));
	if (!trim_str)
		return (NULL);
	i = 0;
	while (i < (slen - trim_start - trim_end))
	{
		trim_str[i] = s1[trim_start + i];
		i++;
	}
	trim_str[i] = '\0';
	return (trim_str);
}

// #include <stdio.h>
// int main (void)
// {
// 	char	*s1 = "!!! !!@@ @!very! @clean!@!!@!@ !@!@";
// 	char	*result;
// 	char	*set = "!@ ";

// 	result = ft_strtrim(s1, set);
// 	printf("%s\n", result);
// 	free(result);
// }
