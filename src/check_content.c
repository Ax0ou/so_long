/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:52:30 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/15 12:32:47 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_pec(t_game *game, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				(*p)++;
			else if (game->map[i][j] == 'E')
				(*e)++;
			else if (game->map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}

int	check_pec(t_game *game)
{
	int	p;
	int	e;
	int	c;

	if (!game || !game->map || !game->map[0])
		return (-1);
	p = 0;
	e = 0;
	c = 0;
	count_pec(game, &p, &e, &c);
	if (p != 1 || e != 1 || c < 1)
		return (-1);
	return (0);
}
