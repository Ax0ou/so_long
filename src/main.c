/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:43:14 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/16 17:40:42 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
	{
		write(1, "Error\nUsage: ./so_long map.ber\n", 31);
		return (1);
	}
	fd = check_arg(argv[1]);
	if (fd == -1)
	{
		write(1, "Error\nInvalid file\n", 19);
		return (1);
	}
	game.map = read_map(fd, argv[1]);
	if (!game.map)
	{
		write(1, "Error\nMap error\n", 16);
		return (1);
	}
	if (get_map_size(&game) == -1)
	{
		write(1, "Error\nMap size error\n", 21);
		return (1);
	}
	if (check_char(&game) == -1)
	{
		write(1, "Error\nMap error\n", 16);
		return (1);
	}
	if (check_rect(&game) == -1)
	{
		write(1, "Error\nMap error\n", 16);
		return (1);
	}
	if (check_wall(&game) == -1)
	{
		write(1, "Error\nMap error\n", 16);
		return (1);
	}
	if (check_pec(&game) == -1)
	{
		write(1, "Error\nMap error\n", 16);
		return (1);
	}
	if (check_path(&game) == -1)
	{
	    write(1, "Error\nMap error\n", 16);
	    return (1);
	}
	if (init_mlx(&game) == -1)
	{
		write(1, "Error\nMlx error\n", 16);
		return (1);
	}
	free_map(game.map);
	return (0);
}
