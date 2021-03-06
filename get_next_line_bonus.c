/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:30:05 by zel-kass          #+#    #+#             */
/*   Updated: 2022/05/31 15:27:27 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_clean(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	j = 0;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i && stash[j])
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (stash[i] && buf[j])
		buf[j++] = stash[i++];
	buf[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int			res;
	char		*line;
	char		*stash;
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	res = BUFFER_SIZE;
	stash = NULL;
	stash = ft_strjoin(stash, buf[fd]);
	while (res == BUFFER_SIZE && !ft_strchr(buf[fd]))
	{
		res = read(fd, buf[fd], BUFFER_SIZE);
		if (res == -1)
			return (free(stash), NULL);
		buf[fd][res] = '\0';
		if (res == 0 && !stash[0])
			return (free(stash), NULL);
		stash = ft_strjoin(stash, buf[fd]);
	}
	line = ft_clean(stash, buf[fd]);
	return (free(stash), line);
}
