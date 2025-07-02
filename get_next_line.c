/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emustafi <elmiramust2010@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:24:32 by emustafi          #+#    #+#             */
/*   Updated: 2025/06/30 16:39:35 by emustafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char buf[BUFFER_SIZE + 1];

	char *line;
	size_t line_len;
	size_t i;

	int num;

	i = 0;
	line_len = 0;

	num = read(fd, buf, BUFFER_SIZE);

	printf("%d\n", num);
	if (num == -1 || num == 0)
		return (NULL);

	buf[num] = '\0';

	while (line_len < (size_t)num && buf[line_len] != '\n')
		line_len++;

	line = malloc(sizeof(char) * (line_len + 1));

	if (!line)
		return (NULL);

	while (i < line_len)
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}