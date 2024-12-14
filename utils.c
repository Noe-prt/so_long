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
        update_player_pos(game, &game->mlx,  &game->win, 'F');
    else if (keycode == 65364)
        update_player_pos(game, &game->mlx,  &game->win, 'B');
    else if (keycode == 65363)
        update_player_pos(game, &game->mlx,  &game->win, 'R');
    else if (keycode == 65361)
        update_player_pos(game, &game->mlx,  &game->win, 'L');
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