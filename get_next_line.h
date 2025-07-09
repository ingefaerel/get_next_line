/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emustafi <emustafi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:24:28 by emustafi          #+#    #+#             */
/*   Updated: 2025/07/09 14:25:10 by emustafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
