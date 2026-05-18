/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:00:07 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/18 15:46:36 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->window = mlx_new_window(game->mlx,
		game->map_size_col * 64,
		game->map_size_row * 64,
		"so_long");
	if (!game->window)
		return (-1);
	return (0);
}

static int	load_one(void *mlx, char *path, void **dest)
{
	int	w;
	int	h;

	*dest = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!*dest)
		return (-1);
	return (0);
}

int	load_textures(t_game *game)
{
	if (load_one(game->mlx, "assets/textures/so_long_pict/wall.xpm",
			&game->img_wall) == -1)
		return (-1);
	if (load_one(game->mlx, "assets/textures/so_long_pict/floor.xpm",
			&game->img_floor) == -1)
		return (-1);
	if (load_one(game->mlx, "assets/textures/so_long_pict/exit.xpm",
			&game->img_exit) == -1)
		return (-1);
	if (load_one(game->mlx, "assets/textures/so_long_pict/collect.xpm",
			&game->img_collect) == -1)
		return (-1);
	if (load_one(game->mlx, "assets/textures/so_long_pict/player.xpm",
			&game->img_player) == -1)
		return (-1);
	return (0);
}

static void	put_tile(t_game *game, int i, int j)
{
	char	c;

	c = game->map[i][j];
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->img_wall, j * 64, i * 64);
	else
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->img_floor, j * 64, i * 64);
		if (c == 'P')
			mlx_put_image_to_window(game->mlx, game->window,
				game->img_player, j * 64, i * 64);
		else if (c == 'C')
			mlx_put_image_to_window(game->mlx, game->window,
				game->img_collect, j * 64, i * 64);
		else if (c == 'E')
			mlx_put_image_to_window(game->mlx, game->window,
				game->img_exit, j * 64, i * 64);
	}
}
int	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			put_tile(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
