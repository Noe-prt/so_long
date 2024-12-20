/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 02:36:31 by nopareti          #+#    #+#             */
/*   Updated: 2024/12/20 08:42:01 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_stash(int fd, char *stash)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_gnl_strchr(stash, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		stash = ft_gnl_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_fill_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_new_stash(stash);
	return (line);
}
/*
int	main(void)
{
	int	fd = open("readme.txt", O_RDONLY);
	for (int i = 0; i < 5; i++)
	{
		printf("%d", i + 1);
		printf(".");
		printf("%s", get_next_line(fd));
		printf("\n");
	}
	return (0);
}
*/
