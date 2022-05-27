/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:33:46 by zel-kass          #+#    #+#             */
/*   Updated: 2022/05/27 17:16:52 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stash_san(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = ft_strchr(stash);
	j = -1;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (++j <= i)
		line[j] = stash[j];
	line[j] = '\0';
	j = 0;
	while (stash[++i])
		buf[j++] = stash[i];
	ft_bzero(&buf[j]);
	free(stash);
	return (line);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*line;
	char		*stash;
	static char	buf[BUFFER_SIZE + 1];

	ret = 1;
	stash = NULL;
	stash = ft_strjoin(stash, buf);
	while (ret && !ft_strchr(buf))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		printf("%d\n", ret);
		stash = ft_strjoin(stash, buf);
	}
	line = ft_stash_san(stash, buf);
	return (line);
}

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);
	printf("%s", str);
	char *str2 = get_next_line(fd);
	printf("%s", str2);
	char *str3 = get_next_line(fd);
	printf("%s", str3);
	// char *str4 = get_next_line(fd);
	// printf("%s", str4);
	// char *str5 = get_next_line(fd);
	// printf("%s", str5);
	// char *str6 = get_next_line(fd);
	// printf("%s", str6);

	// char *line = get_next_line(fd);
	// printf("%s\n", line);
	return (0);
}