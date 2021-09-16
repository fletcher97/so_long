/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:58:49 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/16 03:01:07 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_conv.h"

#include "so_long.h"
#include "logic.h"
#include "map.h"
#include "gui.h"
#include "mlx_keys.h"

void	print_end_msg(t_app *app)
{
	if (app->game.player.dead == 1)
	{
		ft_putstr_fd("Congratulations! You took ", STDOUT);
		ft_putnbr_fd(app->game.steps, STDOUT);
		ft_putendl_fd(" moves to finish.", STDOUT);
	}
	else
		ft_putendl_fd("You died without reaching the end.", STDOUT);
}

static void	move_player(t_app *app, int x, int y, int dir)
{
	if (app->game.map[y][x] == COLL)
		(app->game.map[y][x] = VOID) && app->game.coll_left--;
	place_img(app->mlx, app->screen.img, BASE VOID_XPM,
		(t_pos){app->game.player.x, app->game.player.y});
	if (app->game.map[app->game.player.y][app->game.player.x] == EXIT)
		place_img(app->mlx, app->screen.img, BASE EXIT_XPM,
			(t_pos){app->game.player.x, app->game.player.y});
	((app->game.player.x = x) && 0) || (app->game.player.y = y);
	app->game.steps++;
	app->game.player.dir = dir;
	if (app->game.map[y][x] == EXIT && !app->game.coll_left)
		app->game.player.dead = 1;
	else if (app->game.map[y][x] == ENEM)
		app->game.player.dead = 2;
	render(app, get_frame(app->screen.frame_count));
}

void	move(t_app *app, int key_code)
{
	int	px;
	int	py;
	int	dir;

	px = app->game.player.x;
	py = app->game.player.y;
	dir = 0;
	if (key_code == MLX_KEY_W)
		(py--) && (dir = UP);
	else if (key_code == MLX_KEY_S)
		(py++) && (dir = DOWN);
	else if (key_code == MLX_KEY_A)
		(px--) && (dir = RIGHT);
	else if (key_code == MLX_KEY_D)
		(px++) && (dir = LEFT);
	else
		return ;
	if (app->game.map[py][px] != WALL && 0 < px && px < app->game.width
			&& 0 < py && py < app->game.height && dir)
	{
		move_player(app, px, py, dir);
		printf("%d\n", app->game.steps);
		if (!app->game.player.dead)
			move_enemy(app);
	}
}
