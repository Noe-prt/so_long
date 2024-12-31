/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:39:16 by nopareti          #+#    #+#             */
/*   Updated: 2024/12/31 12:26:03 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(char **map, int x, int y, int *collectibles, int *exit_found)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	if (map[y][x] == 'C')
		(*collectibles)--;
	if (map[y][x] == 'E')
		*exit_found = 1;
	map[y][x] = 'V';
	dfs(map, x + 1, y, collectibles, exit_found);
	dfs(map, x - 1, y, collectibles, exit_found);
	dfs(map, x, y + 1, collectibles, exit_found);
	dfs(map, x, y - 1, collectibles, exit_found);
}

int	check_valid_path(char *map_file)
{
	char	**map;
	t_tuple	player_pos;
	int		collectibles;
	int		exit_found;

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
	dfs(map, player_pos.x, player_pos.y, &collectibles, &exit_found);
	if (collectibles > 0 || !exit_found)
	{
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}
