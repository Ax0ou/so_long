/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:28:03 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/20 13:35:15 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_horiz(t_game *game);

int	get_map_size(t_game *game)
{
	int	y;

	if (!game || !game->map || !game->map[0])
		return (-1);
	y = 0;
	while (game->map[y])
		y++;
	game->map_size_row = y;
	game->map_size_col = ft_strlen(game->map[0]);
	return (0);
}

int	check_char(t_game *game)
{
	int	i;
	int	j;

	if (!game || !game->map || !game->map[0])
		return (-1);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_rect(t_game *game)
{
	int	i;

	if (!game || !game->map || !game->map[0])
		return (-1);
	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->map_size_col)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_horiz(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->map_size_col)
	{
		if (game->map[0][j] != '1')
			return (-1);
		j++;
	}
	j = 0;
	while (j < game->map_size_col)
	{
		if (game->map[game->map_size_row - 1][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

int	check_wall(t_game *game)
{
	int	i;

	if (!game || !game->map || !game->map[0])
		return (-1);
	if (check_horiz(game) == -1)
		return (-1);
	i = 1;
	while (i < game->map_size_row - 1)
	{
		if (game->map[i][0] != '1')
			return (-1);
		if (game->map[i][game->map_size_col - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}
