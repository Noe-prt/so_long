/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:39:16 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/05 18:09:30 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_valid_path(char *map_file)
{
	int		collectibles;
	int		exit_found;
	t_tuple	player_pos;
	char	**map;

	map = parse_map(map_file);
	if (!map)
		return (0);
	player_pos = get_player_pos(map);
	player_pos.x /= 32;
	player_pos.y /= 32;
	if (player_pos.x == -1 || player_pos.y == -1)
		return (0);
	collectibles = get_total_collectible(map);
	exit_found = 0;
	dfs(map, player_pos, &collectibles, &exit_found);
	if (collectibles > 0 || !exit_found)
	{
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}

void	increment_map_requirements(char **map, int *player_count,
		int *exit_count, int *item_count)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				(*player_count)++;
			else if (map[j][i] == 'E')
				(*exit_count)++;
			else if (map[j][i] == 'C')
				(*item_count)++;
			i++;
		}
		j++;
	}
}

int	check_map_requirements(char *map_file)
{
	int		exit_count;
	int		player_count;
	int		item_count;
	char	**map;

	exit_count = 0;
	player_count = 0;
	item_count = 0;
	map = parse_map(map_file);
	increment_map_requirements(map, &exit_count, &player_count, &item_count);
	if (exit_count != 1 || player_count != 1 || item_count == 0)
	{
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}

int	check_map_rectangular(char *map_file)
{
	char	**map;
	int		line_size;
	int		i;
	int		j;

	map = parse_map(map_file);
	line_size = ft_strlen(map[0]);
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			i++;
		}
		if (i != line_size)
		{
			free_map(map);
			return (0);
		}
		j++;
	}
	free_map(map);
	return (1);
}

int	check_map_surrounded_by_walls(char *map_file)
{
	char	**map;
	int		rows;
	int		cols;
	int		i;

	map = parse_map(map_file);
	rows = 0;
	while (map[rows])
		rows++;
	cols = 0;
	while (map[0][cols])
		cols++;
	i = -1;
	while (++i < cols)
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (free_map(map), 0);
	i = -1;
	while (++i < rows)
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (free_map(map), 0);
	free_map(map);
	return (1);
}
