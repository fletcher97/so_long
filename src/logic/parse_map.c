/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:39:50 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/24 20:13:45 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_norm.h"

#include "map.h"

static int	line_to_arr(const char *line, char **out)
{
	int i;

	*out = ft_malloc(ft_strlen(line));
	if (!*out)
		return (0);
	i = -1;
	while (++i < (int) ft_strlen(line))
		(*out)[i] = line[i];
	return (1);
}

static int	map_to_arr(t_app *app, const char *map)
{
	int 	fd;
	int 	i;
	int 	ret;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);

	}
	return (0);
}

int	parse_map(t_app *app, const char *map)
{
	int fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_putstr_fd("Error\nCouldn't read the map.\n", STDERR);
	if (fd == -1)
		return (0);
	close(fd);
	if (!check_map(map))
		return (0);
	map_to_arr(app, map);
	return (1);
}
