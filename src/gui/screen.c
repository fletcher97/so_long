/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:18:51 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/16 02:59:12 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_string.h"

#include "mlx.h"

#include "so_long.h"
#include "gui.h"
#include "map.h"

void	get_screen(t_app *app)
{
	app->screen.height = IMG_SIZE * app->game.height;
	app->screen.width = IMG_SIZE * app->game.width;
	app->screen.title = ft_strdup("so_long");
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	next_frame(t_screen screen, void *mlx)
{
	mlx_put_image_to_window(mlx, screen.win,
		screen.img[0].img, 0, 0);
}

int	get_frame(int fcount)
{
	static int	frame = 1;

	if (fcount % SPEED == 0)
		frame = 1;
	else if ((fcount + SPEED / 2) % SPEED == 0)
		frame = 3;
	else if ((fcount + SPEED / 4) % (SPEED / 2) == 0)
		frame = 2;
	return (frame);
}

void	render(t_app *app, int fcount)
{
	char	*p;

	p = get_player_img(app, get_frame(fcount));
	place_img(app->mlx, app->screen.img, BASE VOID_XPM,
		(t_pos){app->game.player.x, app->game.player.y});
	if (app->game.map[app->game.player.y][app->game.player.x] == COLL)
		place_img(app->mlx, app->screen.img, BASE COLL_XPM,
			(t_pos){app->game.player.x, app->game.player.y});
	else if (app->game.map[app->game.player.y][app->game.player.x] == EXIT)
		place_img(app->mlx, app->screen.img, BASE EXIT_XPM,
			(t_pos){app->game.player.x, app->game.player.y});
	place_img(app->mlx, app->screen.img, p,
		(t_pos){app->game.player.x, app->game.player.y});
}
