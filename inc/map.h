/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:41:21 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/16 04:26:44 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

# define MAP_CHARS "01CEPB"

# define VOID '0'
# define WALL '1'
# define EXIT 'E'
# define COLL 'C'
# define PLAY 'P'
# define ENEM 'B'

int	parse_map(t_app *app, const char *map);
int	check_map(const char *map, t_app *app);
int	check_boudaries(t_game *game);

#endif
