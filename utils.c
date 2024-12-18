/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:59:19 by nopareti          #+#    #+#             */
/*   Updated: 2024/12/13 18:59:19 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tuple	*init_tuple()
{
	t_tuple	*tuple;

	tuple = malloc(sizeof(t_tuple));
	if (!tuple)
		return (NULL);
	tuple->x = 0;
	tuple->y = 0;
	return (tuple);
}

t_game  *init_game(char *map)
{
	t_game	*game;
    int map_fd;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->player_pos = *init_tuple();
	game->player_img = NULL;
    map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
		return (0);
    game->window_size = get_map_size(map_fd);
    close(map_fd);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->window_size->x, game->window_size->y, "Escape Island");
	game->map = map;
	game->steps_count = 0;
	game->collectible_count = 0;
	game->total_collectible = 0;
    map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
		return (0);
    fill_window(map_fd, game);
    close(map_fd);
	return (game);
}

int exit_input(int keycode, void *param)
{
    (void)param;

    if (keycode == 65307)
        exit(0);
    return (0);
}

int movements_inputs(int keycode, void *param)
{
    t_game    *game;

    game = (t_game *)param;
    if (keycode == 65362)
	{
		if (!check_collision(param, 0, -32))
        	update_player_pos(game, &game->mlx,  &game->win, 'F');
	}
    else if (keycode == 65364)
	{
		if (!check_collision(param, 0, 32))
        	update_player_pos(game, &game->mlx,  &game->win, 'B');
	}
    else if (keycode == 65363)
	{
		if (!check_collision(param, 32, 0))
        	update_player_pos(game, &game->mlx,  &game->win, 'R');
	}
    else if (keycode == 65361)
	{
		if (!check_collision(param, -32, 0))
        	update_player_pos(game, &game->mlx,  &game->win, 'L');
	}
    return (0);
}

void update_player_pos(t_game *game, void *mlx, void *win, char direction)
{
    place_sand(&game->player_pos, game);
    if (direction == 'F')
        game->player_pos.y -= 32;
    else if (direction == 'B')
        game->player_pos.y += 32;
    else if (direction == 'R')
        game->player_pos.x += 32;
    else if (direction == 'L')
        game->player_pos.x -= 32;
    mlx_put_image_to_window(game->mlx, game->win, game->player_img, game->player_pos.x, game->player_pos.y);
}

void	handle_inputs(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, movements_inputs, game);
}

char	get_tile_type(int fd, t_tuple pos)
{
	char	*line;
	t_tuple	*curr_pos;
	int	i;

	curr_pos = init_tuple();
	while ((line = get_next_line(fd)))
	{
		i = 0;
		curr_pos->x = 0;
		while (line[i] != '\n')
		{
			if (curr_pos->x == pos.x && curr_pos->y == pos.y)
			{
				free(curr_pos);
				return (line[i]);
			}
			curr_pos->x += 32;
			i++;
		}
		curr_pos->y += 32;
	}
	free(curr_pos);
	return ('\0');
}

int	check_collision(t_game *game, int x, int y)
{
	t_tuple	next_pos;
	int	fd;
	
	fd = open(game->map, O_RDONLY);
	if (fd == -1)
		return (0);
	next_pos.x = game->player_pos.x + x;
	next_pos.y = game->player_pos.y + y;
	if (get_tile_type(fd, next_pos) == '1')
	{
		close(fd);
		return (1);
	}
	close(fd);
	fd = open(game->map, O_RDONLY);
	if (fd == -1)
		return (0);
	else if (get_tile_type(fd, next_pos) == 'C' && !is_already_collected(game, next_pos))
	{
		game->saved_col_pos[game->collectible_count] = next_pos;
		game->collectible_count++;
		if (check_win(game))
		{
			printf("GG WP !\n");
			close(fd);
			exit(0);
		}
	}
	close(fd);
	return (0);
}

int	is_already_collected(t_game *game, t_tuple pos)
{
	int	i;

	i = 0;
	while (i < game->collectible_count)
	{
		if (pos.x == game->saved_col_pos[i].x && pos.y == game->saved_col_pos[i].y)
			return (1);
		i++;
	}
	return (0);
}