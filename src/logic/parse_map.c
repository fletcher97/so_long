/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:39:50 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/15 17:46:50 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_norm.h"

#include "so_long.h"

static int	map_to_arr(t_app *app, const char *map)
{
	(void) app;
	(void) map;
	return (0);
}

int	parse_map(t_app *app, const char *map)
{
	//TODO: checkname
	if (!check_map(map))
		return (0);
	map_to_arr(app, map);
	return (1);
}
