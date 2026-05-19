/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:43:14 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/19 16:51:00 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_all(t_game *game)
{
	if (get_map_size(game) == -1)
    	return (-1);
	if (check_char(game) == -1)
    	return (-1);
	if (check_rect(game) == -1)
    	return (-1);
	if (check_wall(game) == -1)
    	return (-1);
	if (check_pec(game) == -1)
    	return (-1);
	if (check_path(game) == -1)
    	return (-1);
	return (0);
}

static int	init_game(t_game *game, char *path)
{
	int	fd;

	fd = check_arg(path);
	if (fd == -1)
		return (-1);
	game->map = read_map(fd, path);
	if (!game->map)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long map.ber", NULL);
	if (init_game(&game, argv[1]) == -1)
		error_exit("Invalid map file", &game);
	if (check_all(&game) == -1)
		error_exit("Map error", &game);
	if (init_mlx(&game) == -1)
		error_exit("Mlx init error", &game);
	if (load_textures(&game) == -1)
		error_exit("Textures error", &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_hook(game.window, 2, 0, key_handler, &game);
	render_map(&game);
	mlx_loop(game.mlx);
	return (0);
}
