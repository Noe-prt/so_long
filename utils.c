/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:30:36 by nopareti          #+#    #+#             */
/*   Updated: 2024/12/28 18:06:35 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	handle_inputs(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 65362)
		move_up(game);
	else if (keycode == 65364)
		move_down(game);
	else if (keycode == 65363)
		move_right(game);
	else if (keycode == 65361)
		move_left(game);
	else if (keycode == 65307)
		close_game(game);
    return (0);
}

int	get_total_collectible(char **map)
{
	int i;
	int j;
	int count;

	j = 0;
	count = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int	check_map_requirements(char *map_file)
{
	int	i;
	int	j;
	int	exit_count;
	int	player_count;
	int	item_count;
	char**	map;

	j = 0;
	exit_count = 0;
	player_count = 0;
	item_count = 0;
	map = parse_map(map_file);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				player_count++;
			else if (map[j][i] == 'E')
				exit_count++;
			else if (map[j][i] == 'C')
				item_count++;
			i++;
		}
		j++;
	}
	if (exit_count != 1 || player_count != 1 || item_count == 0)
	{
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}

int check_map_rectangular(char *map_file)
{
    int i, j;
    char **map;

    map = parse_map(map_file);
    if (!map)
        return (0);
    j = 0;
    while (map[j])
    {
        if (!map[j][0])
        {
            free_map(map);
            return (0);
        }
        j++;
    }

    i = 0;
    while (map[0][i])
	{
        if (map[0][i] != '1')
        {
            free_map(map);
            return (0);
        }
        i++;
    }
    i = 0;
    while (map[j - 1][i])
    {
        if (map[j - 1][i] != '1')
        {
            free_map(map);
            return (0);
        }
        i++;
    }
    j = 0;
    while (map[j])
    {
        if (map[j][0] != '1' || map[j][i - 1] != '1')
        {
            free_map(map);
            return (0);
        }
        j++;
    }
    free_map(map);
    return (1);
}

