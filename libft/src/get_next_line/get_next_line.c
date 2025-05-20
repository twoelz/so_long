/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-roch <tda-roch@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:30:02 by tda-roch          #+#    #+#             */
/*   Updated: 2025/05/19 01:42:08 by tda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* return values:
	 1 = GNL_SUCCESS
	-1 = GNL_ERROR */
int	set_cache(char **cache, char **buf)
{
	if (!*cache)
	{
		*cache = malloc(sizeof(char));
		if (!*cache)
			return (GNL_ERROR);
		*cache[0] = '\0';
	}
	*buf = malloc((GNL_BUFFER_SIZE + 1) * sizeof(char));
	if (!*buf)
		return (free_strings(cache, buf));
	ft_bzero(*buf, GNL_BUFFER_SIZE + 1);
	return (GNL_SUCCESS);
}

/* return values:
	 1 = GNL_SUCCESS
	 0 = GNL_LAST_LINE
	-1 = GNL_ERROR */
int	load_cache(int fd, char **cache)
{
	char	*buf;
	char	*newcache;
	int		read_bytes;

	if (set_cache(cache, &buf) == GNL_ERROR)
		return (GNL_ERROR);
	read_bytes = 1;
	while (read_bytes > 0 && newline_in_str(*cache) == GNL_ERROR)
	{
		read_bytes = read(fd, buf, GNL_BUFFER_SIZE);
		if (read_bytes == GNL_ERROR)
			return (free_strings(cache, &buf));
		buf[read_bytes] = '\0';
		if (read_bytes == GNL_LAST_LINE)
			return (free_strings(&buf, NULL), GNL_LAST_LINE);
		newcache = ft_strjoin(*cache, buf);
		free_strings(cache, NULL);
		if (newcache == NULL)
			return (free_strings(&buf, NULL));
		*cache = newcache;
		ft_bzero(buf, GNL_BUFFER_SIZE + 1);
	}
	free_strings(&buf, NULL);
	return (GNL_SUCCESS);
}

char	*extract_line(char *cache)
{
	char	*line;
	ssize_t	end_i;

	if (!cache || !ft_strlen(cache))
		return (NULL);
	end_i = newline_in_str(cache);
	if (end_i == GNL_ERROR)
		end_i = ft_strlen(cache);
	else
		end_i += 1;
	line = malloc((end_i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[end_i] = '\0';
	while (end_i--)
		line[end_i] = cache[end_i];
	return (line);
}

char	*extract_newcache(char *cache)
{
	char	*newcache;
	ssize_t	newlen;
	ssize_t	end_i;
	ssize_t	i;

	end_i = newline_in_str(cache);
	if (end_i == GNL_ERROR)
		return (NULL);
	end_i += 1;
	newlen = 0;
	while (cache[end_i + newlen])
		newlen++;
	newcache = malloc((newlen + 1) * sizeof(char));
	if (!newcache)
		return (NULL);
	i = 0;
	while (i < newlen)
	{
		newcache[i] = cache[end_i + i];
		i++;
	}
	newcache[newlen] = '\0';
	return (newcache);
}

char	*get_next_line(int fd)
{
	static char		*cache;
	char			*newcache;
	char			*line;
	int				result;

	if (fd < 0 || GNL_BUFFER_SIZE < 1)
		return (NULL);
	result = load_cache(fd, &cache);
	if (result == GNL_ERROR)
		return (NULL);
	line = extract_line(cache);
	if (line == NULL)
		return (free_strings(&cache, NULL), NULL);
	if (result == GNL_LAST_LINE)
		free_strings(&cache, NULL);
	else if (newline_in_str(cache) != GNL_ERROR)
	{
		newcache = extract_newcache(cache);
		free_strings(&cache, NULL);
		if (!newcache)
			return (NULL);
		cache = newcache;
	}
	return (line);
}
