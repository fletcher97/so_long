/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:15:40 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/15 04:58:17 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_keys.h"
#include "map.h"
#include "so_long.h"
#include "ft_stdio.h"

// static int	init(t_app *app)
// {
// 	t_screen	*s;
// 	t_img		*img;

// 	if (!parse_map(app))
// 		return (0);
// 	app->mlx = mlx_init();
// 	get_screen(&app->screen);
// 	s = &app->screen;
// 	s->win = mlx_new_window(app->mlx, s->width, s->height, s->title);
// 	s->img = ft_malloc(2 * sizeof(t_img));
// 	if (!s->img)
// 		return (0);
// 	img = s->img;
// 	img[0].img = mlx_new_image(app->mlx, s->width, s->height);
// 	img[0].addr = mlx_get_data_addr(img[0].img, &img[0].bpp, &img[0].line,
// 		&img[0].endian);
// 	img[1].img = mlx_new_image(app->mlx, s->width, s->height);
// 	img[1].addr = mlx_get_data_addr(img[1].img, &img[1].bpp, &img[1].line,
// 		&img[1].endian);
// 	return (1);
// }

// void	terminate(t_app app)
// {
// 	mlx_destroy_image(app.mlx, app.screen.img[1].img);
// 	mlx_destroy_image(app.mlx, app.screen.img[0].img);
// 	ft_free(app.screen.img);
// 	mlx_destroy_window(app.mlx, app.screen.win);
// 	ft_free(app.screen.title);
// 	mlx_destroy_display(app.mlx);
// 	ft_free(app.mlx);
// }

// int	stop(int key_code, void *param)
// {
// 	t_app	app;

// 	app = *((t_app *) param);
// 	if (key_code == MLX_KEY_ESC)
// 		terminate(app);
// 	if (key_code == MLX_KEY_ESC)
// 		exit(0);
// 	printf("%d\n", key_code);
// 	return (0);
// }

// int	update(void *param)
// {
// 	char		*frame;
// 	static int	frame_count = 0;
// 	t_app		app;

// 	app = *((t_app *) param);
// 	render(app);
// 	next_frame(app.screen, app.mlx);
// 	frame_count++;
// 	frame = ft_itoa(frame_count);
// 	mlx_string_put(app.mlx, app.screen.win, app.screen.width
// 		- (6 * ft_strlen(frame)), 10, 0x00000000, frame);
// 	ft_free(frame);
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_app	app;

	if (argc != 2)
		ft_putstr_fd("Error\nWrong number of parameter.\n", STDERR);
	if (argc != 2)
		return (1);
	parse_map(&app, argv[1]);
	// if (!init(&app))
	// 	return (1);
	// mlx_key_hook(app.screen.win, stop, &app);
	// mlx_loop_hook(app.mlx, update, &app);
	// mlx_loop(app.mlx);
	return (0);
}
