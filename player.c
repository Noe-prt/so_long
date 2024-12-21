/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 09:28:52 by nopareti          #+#    #+#             */
/*   Updated: 2024/12/20 18:15:40 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(t_game *game)
{
    t_tuple player_pos;

    player_pos = get_player_pos(game);
    if (player_pos.x == -1)
        return ;
    if (game->map[player_pos.y / 32 - 1][player_pos.x / 32] == '1')
        return ;
	if (game->map[player_pos.y / 32 - 1][player_pos.x / 32] == 'C')
		game->collectible_count++;
	if (game->collectible_count == game->total_collectible)
		game->is_open_exit = 1;
	if (game->map[player_pos.y / 32 - 1][player_pos.x / 32] == 'E')
	{
		if (game->is_open_exit)
		{
			printf("GG WP!");
			close_game(game);
			exit(0);
		}
		else
			return ;
	}
    game->map[player_pos.y / 32][player_pos.x / 32] = '0';
    game->map[(player_pos.y / 32) - 1][(player_pos.x / 32)] = 'P';
    draw_window(game);
}

void    move_down(t_game *game)
{
    t_tuple player_pos;

    player_pos = get_player_pos(game);
    if (player_pos.x == -1)
        return ;
    if (game->map[player_pos.y / 32 + 1][player_pos.x / 32] == '1')
        return ;
	if (game->map[player_pos.y / 32 + 1][player_pos.x / 32] == 'C')
		game->collectible_count++;
	if (game->collectible_count == game->total_collectible)
		game->is_open_exit = 1;
	if (game->map[player_pos.y / 32 + 1][player_pos.x / 32] == 'E')
	{
		if (game->is_open_exit)
		{
			ft_printf("GG WP!");
			close_game(game);
			exit(0);
		}
		else
			return ;
	}
    game->map[player_pos.y / 32][player_pos.x / 32] = '0';
    game->map[(player_pos.y / 32) + 1][(player_pos.x / 32)] = 'P';
    draw_window(game);
}

void    move_right(t_game *game)
{
    t_tuple player_pos;

    player_pos = get_player_pos(game);
    if (player_pos.x == -1)
        return ;
	if (game->map[player_pos.y / 32][player_pos.x / 32 + 1] == '1')
        return ;
	if (game->map[player_pos.y / 32][player_pos.x / 32 + 1] == 'C')
		game->collectible_count++;
	if (game->collectible_count == game->total_collectible)
		game->is_open_exit = 1;
	if (game->map[player_pos.y / 32][player_pos.x / 32 + 1] == 'E')
	{
		if (game->is_open_exit)
		{
			printf("GG WP!");
			close_game(game);
			exit(0);
		}
		else
			return ;
	}
    game->map[player_pos.y / 32][player_pos.x / 32] = '0';
    game->map[player_pos.y / 32][(player_pos.x / 32) + 1] = 'P';
    draw_window(game);
}

void    move_left(t_game *game)
{
    t_tuple player_pos;

    player_pos = get_player_pos(game);
    if (player_pos.x == -1)
        return ;
	if (game->map[player_pos.y / 32][player_pos.x / 32 - 1] == '1')
        return ;
	if (game->map[player_pos.y / 32][player_pos.x / 32 - 1] == 'C')
		game->collectible_count++;
	if (game->collectible_count == game->total_collectible)
		game->is_open_exit = 1;
	if (game->map[player_pos.y / 32][player_pos.x / 32 - 1] == 'E')
	{
		if (game->is_open_exit)
		{
			printf("GG WP!");
			close_game(game);
			exit(0);
		}
		else
			return ;
	}
    game->map[player_pos.y / 32][player_pos.x / 32] = '0';
    game->map[player_pos.y / 32][(player_pos.x / 32) - 1] = 'P';
    draw_window(game);
}

t_tuple get_player_pos(t_game *game)
{
    int i;
    int j;
    t_tuple player_pos;

    j = 0;
    while (game->map[j])
    {
        i = 0;
        while (game->map[j][i])
        {
            if (game->map[j][i] == 'P')
            {
                player_pos.x = i * 32;
                player_pos.y = j * 32;
                return (player_pos);
            }
            i++;
        }
        j++;
    }
    player_pos.x = -1;
    player_pos.y = -1;
    return (player_pos);
}