/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:28:03 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/13 17:02:01 by aalvard          ###   ########.fr       */
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
