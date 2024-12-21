/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:54:46 by nopareti          #+#    #+#             */
/*   Updated: 2024/12/21 11:35:35 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game  *init_game(char *map_file)
{
    t_game *game;
	t_tuple	tile_size;

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
    draw_window(game);
    return (game);
}

void	draw_window(t_game *game)
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
                mlx_put_image_to_window(game->mlx, game->win, game->wall_img, i * 32, j * 32);
			else if (game->map[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor_img, i * 32, j * 32);
			else if (game->map[j][i] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, i * 32, j * 32);
			else if (game->map[j][i] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, i * 32, j * 32);
			else if (game->map[j][i] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, i * 32, j * 32);
			i++;
        }
		j++;
    }
}

t_tuple	get_window_size(char **map)
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

char    **parse_map(char *map_file)
{
    char    *old_map;
    char    **new_map;
    int     map_fd;
    int     i;
    int     line_count;
    size_t  line_len;

    map_fd = open(map_file, O_RDONLY);
    if (map_fd == -1)
        exit(-1);
    i = 0;
    line_count = 0;
    while ((old_map = get_next_line(map_fd)))
    {
        free(old_map);
        line_count++;
    }
    new_map = malloc(sizeof(char *) * (line_count + 1));
    if (!new_map)
        return (NULL);
    close(map_fd);
    map_fd = open(map_file, O_RDONLY);
    if (map_fd == -1)
        exit(-1);
    while ((old_map = get_next_line(map_fd)))
    {
        line_len = ft_strlen(old_map);
        if (old_map[line_len - 1] == '\n')
            old_map[line_len - 1] = '\0';

        new_map[i] = malloc(sizeof(char) * (ft_strlen(old_map) + 1));
        if (!new_map[i])
        {
            free(new_map);
            free(old_map);
            close(map_fd);
            return (NULL);
        }
        ft_strcpy(new_map[i], old_map);
        free(old_map);
        i++;
    }
    if (old_map)
        free(old_map);
    new_map[i] = NULL;
    close(map_fd);
    return (new_map);
}

