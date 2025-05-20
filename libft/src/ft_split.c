/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:43:48 by tda-roch          #+#    #+#             */
/*   Updated: 2024/10/18 12:06:07 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_result(char **result, int numstrs)
{
	int	i;

	i = 0;
	while (i < numstrs)
	{
		if (result[i] != NULL)
			free(result[i]);
		i++;
	}
	free(result);
}

static int	get_numstrings(char const *s, char const c)
{
	int	numstrings;
	int	i;

	numstrings = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		numstrings++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (numstrings);
}

static char	*get_next_str(int *str_i, char const *s, char const c)
{
	int		slen;
	int		spos;
	int		i;
	char	*subs;

	while (s[*str_i] != '\0' && s[*str_i] == c)
		(*str_i)++;
	spos = *str_i;
	slen = 0;
	while (s[*str_i] != '\0' && s[*str_i] != c)
	{
		slen++;
		(*str_i)++;
	}
	subs = malloc((slen + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (s[spos] != '\0' && s[spos] != c)
		subs[i++] = s[spos++];
	subs[i] = '\0';
	return (subs);
}

/*
	Allocates (with malloc) and returns an array of strings obtained by 
	splitting ’s’ using the character ’c’ as a delimiter. The array must end 
	with a NULL pointer.
	Returns NULL if allocation fails/
*/
char	**ft_split(char const *s, const char c)
{
	char	**result;
	int		numstrs;
	int		str_count;
	int		str_i;

	str_count = 0;
	str_i = 0;
	numstrs = get_numstrings(s, c);
	result = malloc((numstrs + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (str_count < numstrs)
	{
		result[str_count] = get_next_str(&str_i, s, c);
		if (!result[str_count])
		{
			free_result(result, str_count);
			return (NULL);
		}
		str_count++;
	}
	result[str_count] = NULL;
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	**split1;
// 	int		i;
// 	split1 = ft_split("oi bom dia amanha\n   vamos a la    playa", ' ');
// 	if (split1 == 0)
// 		return (1);
// 	i = 0;
// 	while (split1[i] != 0)
// 	{
// 		printf("split1[%d] = %s\n", i, split1[i]);
// 		free(split1[i]);
// 		i++;
// 	}
// 	free(split1);
// 	return (0);
// }
