/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:04:39 by aalvard           #+#    #+#             */
/*   Updated: 2026/04/09 20:40:06 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**fill_map(char *path, int count);

int	check_arg(char *path)
{
	int	fd;

	if (ft_strncmp(path + (ft_strlen(path) - 4), ".ber", 4) != 0)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

char	**read_map(int fd, char *path)
{
	char	*line;
	int		count;

	if (!fd || !*path)
		return (0);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (fill_map(path, count));
}

static char	**fill_map(char *path, int count)
{
	char	**map;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc((count + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
