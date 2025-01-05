/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:54:50 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/05 18:14:19 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define TILE_SIZE 32
# define WALL_PATH "assets/WATER.xpm"
# define FLOOR_PATH "assets/SAND.xpm"
# define PLAYER_PATH "assets/PIRATE.xpm"
# define COLLECTIBLE_PATH "assets/STICK.xpm"
# define EXIT_PATH "assets/EXIT.xpm"

typedef struct s_tuple
{
	int	x;
	int	y;
}				t_tuple;

typedef struct s_game
{
	char		*wall_img;
	char		*floor_img;
	char		*player_img;
	char		*collectible_img;
	char		*exit_img;
	char		**map;
	void		*mlx;
	void		*win;
	t_tuple		window_size;
	int			collectible_count;
	int			total_collectible;
	int			is_open_exit;
	int			movements_count;
}				t_game;

t_game	*init_game(char *map_file);
char	**parse_map(char *map_file);
char	*ft_strcpy(char *s1, char *s2);
t_tuple	get_window_size(char **map);
void	draw_window(t_game *game);
int		handle_inputs(int keycode, void *param);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
t_tuple	get_player_pos(char **map);
int		get_total_collectible(char **map);
int		close_game(t_game *game);
int		check_map_requirements(char *map_file);
int		check_map_rectangular(char *map_file);
void	free_map(char **map);
int		check_valid_path(char *map_file);
int		check_map_surrounded_by_walls(char *map_file);
void	dfs(char **map, t_tuple pos, int *collectibles, int *exit_found);

#endif
