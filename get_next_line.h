/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-kass <zel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:34:36 by zel-kass          #+#    #+#             */
/*   Updated: 2022/05/27 17:17:23 by zel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 1

#endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
int		ft_llen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
void	ft_bzero(void *s);

#endif