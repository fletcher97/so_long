/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 01:00:48 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/16 02:26:00 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "so_long.h"
#include "map.h"
#include "gui.h"
#include "logic.h"

static int	get_rand(void)
{
	static int	f = 1;

	if (f)
		srandom(SEED);
	if (f)
		f = !f;
	return ((random() % 4) + 1);
}

static int	move_e(t_app *app, int e)
{
	int	x;
	int	y;
	int	rand;

	((x = app->game.enemy[e].x) && 0) || (y = app->game.enemy[e].y);
	rand = get_rand();
	if (rand == RIGHT)
		x++;
	else if (rand == LEFT)
		x--;
	else if (rand == UP)
		y++;
	else if (rand == DOWN)
		y--;
	if (app->game.map[y][x] != VOID && app->game.map[y][x] != PLAY)
		return (0);
	app->game.map[app->game.enemy[e].y][app->game.enemy[e].x] = VOID;
	((app->game.enemy[e].x = x) && 0) || (app->game.enemy[e].y = y);
	app->game.map[app->game.enemy[e].y][app->game.enemy[e].x] = ENEM;
	if (app->game.player.x == app->game.enemy[e].x
		&& app->game.player.y == app->game.enemy[e].y)
		app->game.player.dead = 2;
	return (1);
}

void	move_enemy(t_app *app)
{
	int	i;
	int	f;

	i = 0;
	while (i < app->game.en_count)
	{
		place_img(app->mlx, app->screen.img, BASE VOID_XPM,
			(t_pos){app->game.enemy[i].x, app->game.enemy[i].y});
		f = move_e(app, i);
		place_img(app->mlx, app->screen.img, BASE ENEM_XPM,
			(t_pos){app->game.enemy[i].x, app->game.enemy[i].y});
		if (f)
			i++;
	}
}
