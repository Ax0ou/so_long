/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvarad <aalvarad.studient.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:50:34 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/20 11:45:39 by aalvarad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_game *game)
{
	if (keycode == 53 || keycode == 65307)
		close_game(game);
	else if (keycode == 13 || keycode == 126
		|| keycode == 119 || keycode == 65362)
		move_player(game, -1, 0);
	else if (keycode == 1 || keycode == 125
		|| keycode == 115 || keycode == 65364)
		move_player(game, 1, 0);
	else if (keycode == 0 || keycode == 123
		|| keycode == 97 || keycode == 65361)
		move_player(game, 0, -1);
	else if (keycode == 2 || keycode == 124
		|| keycode == 100 || keycode == 65363)
		move_player(game, 0, 1);
	return (0);
}

int	move_player(t_game *game, int move_y, int move_x)
{
	int	new_y;
	int	new_x;

	new_y = game->player_y + move_y;
	new_x = game->player_x + move_x;
	if (game->map[new_y][new_x] == '1')
		return (0);
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collect == 0)
			close_game(game);
		return (0);
	}
	if (game->map[new_y][new_x] == 'C')
		game->collect--;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_y = new_y;
	game->player_x = new_x;
	game->moves++;
	ft_printf("Mouvements: %d\n", game->moves);
	render_map(game);
	return (0);
}

int	close_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}
