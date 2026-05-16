/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:00:07 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/16 17:04:21 by aalvard          ###   ########.fr       */
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
