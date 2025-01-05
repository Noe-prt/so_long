/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:54:52 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/05 17:59:42 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_with_msg(char *msg)
{
	ft_printf("%s", msg);
	exit(-1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		exit_with_msg("Error\nso_long need a [MAP FILE] to work\n");
	if (!check_map_requirements(argv[1]))
		exit_with_msg("Error\nMap need 1 player, 1 item and exit !\n");
	if (!check_map_rectangular(argv[1]))
		exit_with_msg("Error\nMap must be rectangular !\n");
	if (!check_map_surrounded_by_walls(argv[1]))
		exit_with_msg("Error\nMap must be surrounded by walls !\n");
	if (!check_valid_path(argv[1]))
		exit_with_msg("Error\nThis map can't be winnable !\n");
	game = init_game(argv[1]);
	mlx_hook(game->win, 2, 1L << 0, handle_inputs, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
