/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:00:00 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/05 18:00:00 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	dfs(char **map, t_tuple pos, int *collectibles, int *exit_found)
{
	t_tuple	local_pos;

	local_pos.x = 0;
	local_pos.y = 0;
	if (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'V')
		return ;
	if (map[pos.y][pos.x] == 'C')
		(*collectibles)--;
	if (map[pos.y][pos.x] == 'E')
		*exit_found = 1;
	map[pos.y][pos.x] = 'V';
	local_pos.x = pos.x + 1;
	local_pos.y = pos.y;
	dfs(map, local_pos, collectibles, exit_found);
	local_pos.x = pos.x - 1;
	local_pos.y = pos.y;
	dfs(map, local_pos, collectibles, exit_found);
	local_pos.x = pos.x;
	local_pos.y = pos.y + 1;
	dfs(map, local_pos, collectibles, exit_found);
	local_pos.x = pos.x;
	local_pos.y = pos.y - 1;
	dfs(map, local_pos, collectibles, exit_found);
}
