/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalvard <aalvarad@student.42lausanne.ch    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:44:33 by aalvard           #+#    #+#             */
/*   Updated: 2026/05/15 17:18:39 by aalvard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_game
{
	int		player_x;
	int		player_y;
	int		moves;
	int		map_size_col;
	int		map_size_row;
	char	**map;
	int		collect;
	void	*mlx;
	void	*window;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
}	t_game;

int		check_arg(char *path);
char	**read_map(int fd, char *path);
int		get_map_size(t_game *game);
int		check_char(t_game *game);
int		check_rect(t_game *game);
int		check_wall(t_game *game);
int		check_pec(t_game *game);
int		check_path(t_game *game);
int		find_player(t_game *game);
void	free_map(char **map);
#endif
