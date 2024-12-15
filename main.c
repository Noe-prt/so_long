#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	*game;

    if (argc != 2)
        return (0);
	game = init_game(argv[1]);
	handle_inputs(game);
    mlx_loop(game->mlx);
}

t_tuple	*get_map_size(int	map_fd)
{
	t_tuple	*size;
	char	*line;
	int	i;

	size = init_tuple();
	i = 0;
	while ((line = get_next_line(map_fd)))
	{
		if (size->x == 0)
		{
			while (line[i] != '\n')
			{
				size->x += 32;
				i++;
			}
		}
		size->y += 32;
	}
	return (size);
}

void	fill_window(int	map_fd, t_game *game)
{
	char	*line;
	t_tuple	*pos;
	int	i;

	pos = init_tuple();
	i = 0;
	while ((line = get_next_line(map_fd)))
	{
		i = 0;
		pos->x = 0;
		while (line[i])
		{
			if (line[i] == '1')
				place_water(pos, game);
			else if (line[i] == '0')
				place_sand(pos, game);
			else if (line[i] == 'P')
				place_player(pos, game);
			else if (line[i] == 'C')
			{
				game->total_collectible++;
				place_collectible(pos, game);
			}
			else if (line[i] == 'E')
				place_sand(pos, game);
			pos->x += 32;
			i++;
		}
		pos->y += 32;
	}
}

void	place_sand(t_tuple*	pos, t_game *game)
{
	void	*img;
	t_tuple	*size;
	char	*path = "./SAND.xpm";

	size = init_tuple();
	size->x = 32;
	size->y = 32;
	img = mlx_xpm_file_to_image(game->mlx, path, &size->x, &size->y);
	if (!img)
	{	
	    perror("Error loading image");
    	return;
	}
    mlx_put_image_to_window(game->mlx, game->win, img, pos->x, pos->y);
}

void	place_water(t_tuple* pos, t_game *game)
{
	void	*img;
	t_tuple	*size;
	char	*path = "./WATER.xpm";

	size = init_tuple();
	size->x = 32;
	size->y = 32;
	img = mlx_xpm_file_to_image(game->mlx, path, &size->x, &size->y);
	if (!img)
	{	
	    perror("Error loading image");
    	return;
	}
    mlx_put_image_to_window(game->mlx, game->win, img, pos->x, pos->y);
}

void	place_collectible(t_tuple* pos, t_game *game)
{
	void	*img;
	t_tuple	*size;
	char	*path = "./collectible.xpm";

	size = init_tuple();
	size->x = 32;
	size->y = 32;
	img = mlx_xpm_file_to_image(game->mlx, path, &size->x, &size->y);
	if (!img)
	{	
	    perror("Error loading image");
    	return;
	}
    mlx_put_image_to_window(game->mlx, game->win, img, pos->x, pos->y);
}

void	place_player(t_tuple* pos, t_game *game)
{
	void	*img;
	t_tuple	*size;
	char	*path = "./player.xpm";

	size = init_tuple();
	size->x = 32;
	size->y = 32;
	img = mlx_xpm_file_to_image(game->mlx, path, &size->x, &size->y);
	game->player_pos = *pos;
	game->player_img = img;
    mlx_put_image_to_window(game->mlx, game->win, img, pos->x, pos->y);
}

int	check_win(t_game *game)
{
	if (game->collectible_count == game->total_collectible)
		return (1);
	return (0);
}