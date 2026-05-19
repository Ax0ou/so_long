/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:09:52 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/19 10:47:34 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood(char **map, int i, int j);
static char	**dup_map(char **map, int rows);

int	find_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (!game || !game->map || !game->map[0])
		return (-1);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
			}
			j++;
		}
		i++;
	}
	return (0);
}

static void	flood(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'F')
		return ;
	map[i][j] = 'F';
	flood(map, i + 1, j);
	flood(map, i - 1, j);
	flood(map, i, j + 1);
	flood(map, i, j - 1);
}

static char	**dup_map(char **map, int rows)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc((rows + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	while (i < rows)
	{
		new[i] = ft_strdup(map[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

int	check_path(t_game *game)
{
	char	**copy;
	int		i;
	int		j;
	int		ret;

	if (!game || !game->map || !game->map[0])
		return (-1);
	find_player(game);
	copy = dup_map(game->map, game->map_size_row);
	flood(copy, game->player_y, game->player_x);
	i = 0;
	ret = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				ret = -1;
			j++;
		}
		i++;
	}
	free_map(copy);
	return (ret);
}
