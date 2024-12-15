#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"

#ifndef SO_LONG_H
#define SO_LONG_H

typedef struct s_tuple
{
	int	x;
	int	y;
}			t_tuple;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_tuple	*window_size;
	t_tuple	player_pos;
	void	*player_img;
	char	*map;
	int	collectible_count;
	int	total_collectible;
	int	steps_count;
	t_tuple	saved_col_pos[255];
}			t_game;

t_tuple	*get_map_size(int	map_fd);
void	fill_window(int	map_fd, t_game *game);
void	place_sand(t_tuple*	pos, t_game *game);
void	place_water(t_tuple* pos, t_game *game);
void	place_player(t_tuple* pos, t_game *game);
void	place_collectible(t_tuple* pos, t_game *game);
void	handle_inputs(t_game *game);
int movements_inputs(int keycode, void *param);
int exit_input(int keycode, void *param);
t_tuple	*init_tuple();
t_game  *init_game(char *map);
void update_player_pos(t_game *game, void *mlx, void *win, char direction);
char	get_tile_type(int fd, t_tuple pos);
int	check_collision(t_game *game, int x, int y);
int	is_already_collected(t_game *game, t_tuple pos);
int	check_win(t_game *game);

#endif