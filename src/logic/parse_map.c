/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:39:50 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/15 02:59:30 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_norm.h"

#include "map.h"
#include "logic.h"

static int	map_to_arr(t_game *game, const char *map)
{
	int		fd;
	int		i;
	int		ret;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	ret = 1;
	game->map = ft_calloc(game->height, sizeof(char *));
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ft_strlen(line) > 0)
			game->map[i++] = line;
		else
			ft_free(line);
	}
	return (ret);
}

static int	map_read_cont(t_game *game)
{
	int	i;
	int	j;
	int	exit;

	(i = -1) && (exit = 0);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == PLAY)
			{
				game->map[i][j] = VOID;
				game->player.x = j;
				game->player.y = i;
				game->player.dir = LEFT;
			}
			else if (game->map[i][j] == COLL)
				game->coll_left++;
			else if (game->map[i][j] == EXIT)
				exit = 1;
		}
	}
	return (exit && game->coll_left > 0 && game->player.dir);
}

int	parse_map(t_app *app, const char *map)
{
	int	fd;
	int	size;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error\nCouldn't read the map.\n", STDERR);
	if (fd == -1)
		return (0);
	close(fd);
	size = check_map(map, app);
	if (!size)
		return (0);
	map_to_arr(&(app->game), map);
	if (!map_read_cont(&(app->game)))
		ft_putstr_fd("Error\nMap is missing elements.\n", STDERR);
	return (1);
}
