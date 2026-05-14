/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:28:03 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/14 14:40:24 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_size(t_game *game)
{
	int	y;

	if (!game || !game->map || !game->map[0])
		return (-1);
	y = 0;
	while (game->map[y])
		y++;
	game->map_size_row = y;
	game->map_size_col = ft_strlen(game->map[0]) - 1;
	return (0);
}

int    check_char(t_game *game)
{
    int    i;
    int    j;

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
                && game->map[i][j] != 'P' && game->map[i][j] != '\n')
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

