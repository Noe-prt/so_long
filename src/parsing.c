/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:11:57 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/05 13:11:57 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**alloc_and_init_map(int *map_fd, int *line_count, char *old_map)
{
	char	**new_map;
	if (*map_fd == -1)
	{
		ft_printf("Error\nMap file is invalid !\n");
		exit(-1);
	}
	*line_count = 0;
	while ((old_map = get_next_line(*map_fd)))
	{
		free(old_map);
		(*line_count)++;
	}
	new_map = malloc(sizeof(char *) * (*line_count + 1));
	if (!new_map)
		return (NULL);
	close(*map_fd);
	return (new_map);
}

int	alloc_and_set_line(char **new_map, int *i, char *old_map, int *map_fd)
{
	new_map[*i] = malloc(sizeof(char) * (ft_strlen(old_map) + 1));
	if (!new_map[*i])
	{
		free(new_map);
		free(old_map);
		close(*map_fd);
		return (0);
	}
	ft_strcpy(new_map[*i], old_map);
	free(old_map);
	return (1);
}

void	replace_if_endline(char *old_map)
{
	size_t	line_len;
	
	line_len = ft_strlen(old_map);
	if (old_map[line_len - 1] == '\n')
		old_map[line_len - 1] = '\0';
}

char **parse_map(char *map_file)
{
	char *old_map;
	char **new_map;
	int map_fd;
	int i;
	int line_count;
	
	map_fd = open(map_file, O_RDONLY);
	old_map = NULL;
	new_map = alloc_and_init_map(&map_fd, &line_count, old_map);
	map_fd = open(map_file, O_RDONLY);
	i = 0;
	while ((old_map = get_next_line(map_fd)))
	{
		replace_if_endline(old_map);
		if (!alloc_and_set_line(new_map, &i, old_map, &map_fd))
			return (NULL);
		i++;
	}
	if (old_map)
		free(old_map);
	new_map[i] = NULL;
	close(map_fd);
	return (new_map);
}