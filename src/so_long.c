/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 02:42:30 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/16 21:30:45 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "mlx.h"

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_conv.h"
#include "ft_string.h"

#include "mlx_keys.h"
#include "map.h"
#include "logic.h"
#include "gui.h"
#include "so_long.h"

static int	init(t_app *app, char **argv)
{
	t_screen	*s;
	t_img		*img;

	if (!parse_map(app, argv[1]))
		return (0);
	app->mlx = mlx_init();
	get_screen(app);
	s = &app->screen;
	s->win = mlx_new_window(app->mlx, s->width, s->height, s->title);
	s->img = ft_malloc(1 * sizeof(t_img));
	if (!s->img)
		return (0);
	img = s->img;
	img->img = mlx_new_image(app->mlx, s->width, s->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line,
			&img->endian);
	return (buildbg(app));
}

void	terminate(t_app *app, int i)
{
	print_end_msg(app);
	if (app->mlx && app->screen.img && app->screen.img->img)
		mlx_destroy_image(app->mlx, app->screen.img->img);
	if (app->screen.img)
		ft_free(app->screen.img);
	if (app->mlx && app->screen.win)
		mlx_destroy_window(app->mlx, app->screen.win);
	if (app->screen.title)
		ft_free(app->screen.title);
	if (app->mlx)
		ft_free(app->mlx);
	i = -1;
	while (++i < app->game.height)
		if (app->game.map && app->game.map[i])
			ft_free(app->game.map[i]);
	if (app->game.enemy)
		ft_free(app->game.enemy);
	if (app->game.map)
		ft_free(app->game.map);
	ft_free(app);
	exit(0);
}

int	stop(int key_code, void *param)
{
	t_app	*app;

	app = ((t_app *) param);
	if (key_code == MLX_KEY_ESC || app->game.player.dead)
		terminate(app, 0);
	if (key_code == MLX_KEY_W || key_code == MLX_KEY_A || key_code == MLX_KEY_S
		|| key_code == MLX_KEY_D)
		move(app, key_code);
	return (0);
}

int	update(void *param)
{
	char		*steps_string;
	t_app		*app;

	app = ((t_app *) param);
	if (app->game.player.dead)
		terminate(app, 0);
	render(app, app->screen.frame_count++);
	next_frame(app->screen, app->mlx);
	steps_string = ft_itoa(app->game.steps);
	mlx_string_put(app->mlx, app->screen.win, 0, 10, 0x00FFFFFF, steps_string);
	ft_free(steps_string);
	mlx_do_sync(app->mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_app	*app;

	if (argc != 2)
		ft_putstr_fd("Error\nWrong number of parameter.\n", STDERR);
	if (argc != 2)
		return (1);
	app = ft_calloc(1, sizeof(t_app));
	if (!init(app, argv))
		terminate(app, 0);
	mlx_key_hook(app->screen.win, stop, app);
	mlx_loop_hook(app->mlx, update, app);
	mlx_hook(app->screen.win, 17, (1L << 17), stop_hook, app);
	mlx_loop(app->mlx);
	return (0);
}
