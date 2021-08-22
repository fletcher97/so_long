/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:44:12 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/15 17:57:17 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <fcntl.h>

#include "ft_stdio.h"
#include "ft_stdlib.h"

int	check_size(const char *map)
{
	int		fd;
	int		ret;
	size_t	size;
	char	*line;

	fd = open(map, O_RDONLY);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		ft_putstr_fd("Error\nCouldn't read the map.\n", STDERR);
	if (ret == 0)
		ft_putstr_fd("Error\nMap is empty or has only one line.\n", STDERR);
	if (ret <= 0)
		return (0);
	ft_free(line);
}

int	check_rect(const char *map)
{
	int		fd;
	int		ret;
	size_t	size;
	char	*line;

	fd = open(map, O_RDONLY);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		ft_putstr_fd("Error\nCouldn't read the map.\n", STDERR);
	if (ret == 0)
		ft_putstr_fd("Error\nMap is empty or has only one line.\n", STDERR);
	if (ret <= 0)
		return (0);
	size = ft_strlen(line);
	ft_free(line);
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret && ft_strlen(line) != size)
			ret = -1;
		ft_free(line);
		if (ret == -1)
			break ;
	}
	return ((close(fd) && 0) || ret != -1);
}

int	check_cont(const char *map)
{
	(void) map;
	return (0);
}

int	check_map(const char *map)
{
	int	lines;

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
	return (lines);
}
