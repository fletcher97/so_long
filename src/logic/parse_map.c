/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:39:50 by mgueifao          #+#    #+#             */
/*   Updated: 2021/07/12 02:47:35 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#include "so_long.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_norm.h"

static int check_rect(const char *map)
{
	int fd;
	int ret;
	int size;
	char *line;

	fd = open(map, O_RDONLY);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		ft_putstr_fd("Error\nCouldn't read the map.\n", STDERR);
	if (ret == 0)
		ft_putstr_fd("Error\nMap is empty.\n", STDERR);
	if (ret <=0)
		return (0);
	size = strlen(line);
	ft_free(line);
	while (ret)
	{
		ret = get_next_line(fd, line);
		if (ret && ft_strlen(line) != size)
			ret = -1;
		ft_free(line);
		if (ret == -1)
			break;
	}
	close(fd);
	return (ret != -1);
}

static int check_map(const char *map)
{
	int fd;
	int lines;

	lines = check_rect(map);
	if (!lines)
		ft_putstr_fd("Error\nMap is not rectangle.\n", STDERR);
	if (!lines)
		return (0);
	lines = check_cont(map);
	if (!lines)
		ft_putstr_fd("Error\nMap contains unknown char.\n", STDERR);
	if (!lines)
		return (0);
	close(fd);
	return (lines);
}

int parse_map(t_app *app, const char *map)
{
	if (!check_map(map))
		return (0);
	map_to_arr(app, map);
	return (1);
}
