/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:54:46 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/05 13:12:35 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game *init_game(char *map_file)
{
	t_game *game;
	t_tuple tile_size;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = parse_map(map_file);
	game->mlx = mlx_init();
	game->window_size = get_window_size(game->map);
	game->win = mlx_new_window(game->mlx, game->window_size.x, game->window_size.y, "Escape Island");
	tile_size.x = TILE_SIZE;
	tile_size.y = TILE_SIZE;
	game->floor_img = mlx_xpm_file_to_image(game->mlx, FLOOR_PATH, &tile_size.x, &tile_size.y);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, WALL_PATH, &tile_size.x, &tile_size.y);
	game->player_img = mlx_xpm_file_to_image(game->mlx, PLAYER_PATH, &tile_size.x, &tile_size.y);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE_PATH, &tile_size.x, &tile_size.y);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, EXIT_PATH, &tile_size.x, &tile_size.y);
	game->collectible_count = 0;
	game->total_collectible = get_total_collectible(game->map);
	game->is_open_exit = 0;
	game->movements_count = 0;
	draw_window(game);
	return (game);
}

void draw_window(t_game *game)
{
	int i;
	int j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_img, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[j][i] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[j][i] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, i * TILE_SIZE, j * TILE_SIZE);
			else if (game->map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, i * TILE_SIZE, j * TILE_SIZE);
			i++;
		}
		j++;
	}
	ft_printf("Mouvements : %d\n", game->movements_count);
}

t_tuple get_window_size(char **map)
{
	t_tuple size;
	int i;

	i = 0;
	while (map[0][i])
		i++;
	size.x = i * TILE_SIZE;
	i = 0;
	while (map[i])
	{
		i++;
	}
	size.y = i * TILE_SIZE;
	return (size);
}
