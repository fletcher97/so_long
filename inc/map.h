/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:41:21 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/15 17:47:31 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

int	parse_map(t_app *app, const char *map);
int	check_rect(const char *map);
int	check_cont(const char *map);
int	check_map(const char *map);

#endif
