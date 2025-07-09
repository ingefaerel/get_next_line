/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emustafi <emustafi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:24:32 by emustafi          #+#    #+#             */
/*   Updated: 2025/07/09 15:14:13 by emustafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static int	is_newline(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

static char	*append_to_stash(char *stash, char *buf, int num)
{
	int		stash_len;
	char	*temp;

	stash_len = ft_strlen(stash);
	temp = malloc(stash_len + num + 1);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, stash, stash_len);
	ft_memcpy(temp + stash_len, buf, num);
	temp[stash_len + num] = '\0';
	free(stash);
	return (temp);
}

static char	*create_stash(int fd, char **stash)
{
	int		num;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	num = 1;
	if (!(*stash))
		*stash = ft_strdup("");
	while (num > 0 && !is_newline(*stash))
	{
		num = read(fd, buf, BUFFER_SIZE);
		if (num == -1)
			return (free(*stash), free(buf), NULL);
		buf[num] = '\0';
		*stash = append_to_stash(*stash, buf, num);
		if (!(*stash))
			return (free(buf), NULL);
	}
	free(buf);
	if (num == 0 && (!*stash || (*stash)[0] == '\0'))
		return (free(*stash), NULL);
	return (*stash);
}

static char	*prepare_stash(char *stash, int len)
{
	char	*new_stash;

	new_stash = ft_strdup(stash + len);
	free(stash);
	stash = new_stash;
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			len;
	int			i;

	len = 0;
	i = 0;
	stash = create_stash(fd, &stash);
	if (!stash)
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] && stash[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	stash = prepare_stash(stash, len);
	return (line);
}
