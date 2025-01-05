/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:54:52 by nopareti          #+#    #+#             */
/*   Updated: 2025/01/05 15:13:19 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	handle_errors(char *arg)
{
	if (argc != 2)
	{
		ft_printf("Error\nso_long need a [MAP FILE] to work\n");
		return (0);
	}
	if (!check_map_requirements(argv[1]))
	{
		ft_printf("Error\nMap need [1 PLAYER] [1 EXIT] [1 ITEM OR MORE] !\n");
		return (-1);
	}
	if (!check_map_rectangular(argv[1]))
	{
		ft_printf("Error\nMap must be rectangular and surrounded by walls !\n");
		return (-1);
	}
	if (!check_valid_path(argv[1]))
	{
		ft_printf("Error\nThis map can't be winnable!\n");
		return (-1);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	handle_errors(argv[1]);
	game = init_game(argv[1]);
	mlx_hook(game->win, 2, 1L << 0, handle_inputs, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
