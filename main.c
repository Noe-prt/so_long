/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 05:54:52 by nopareti          #+#    #+#             */
/*   Updated: 2024/12/20 08:34:59 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  *game;

    if (argc != 2)
    {
        return (0);
    }
    game = init_game(argv[1]);
    mlx_hook(game->win, 2, 1L << 0, handle_inputs, game);
    mlx_loop(game->mlx);
}