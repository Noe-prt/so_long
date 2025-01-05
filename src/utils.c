/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:30:36 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/05 13:13:07 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	int	i;
	int	j;
	int	count;

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
