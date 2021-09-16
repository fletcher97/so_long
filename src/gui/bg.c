/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 00:49:19 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/16 02:19:34 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"

#include "so_long.h"
#include "map.h"
#include "gui.h"

#include "mlx.h"

int	place_img(void *mlx, t_img *dst, char *path, t_pos p)
{
	t_img	img;
	int		i;
	int		j;
	int		width;
	int		height;

	img.img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!img.img)
		ft_putstr_fd("Error\nWrong path to image.\n", STDERR);
	if (!img.img)
		return (0);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line, &img.endian);
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			if ((*(int *)(img.addr + (i * img.line + j * (img.bpp / 8)))
				& 0xff000000) != 0xff000000)
				my_mlx_pixel_put(dst, p.x * width + j,
					p.y * height + i, *(int *)(img.addr + (i * img.line + j
							* (img.bpp / 8))));
	}
	return (mlx_destroy_image(mlx, img.img) || 1);
}

static char	*place_w_trans(t_app *app, t_pos p)
{
	char	*path;

	if (app->game.map[p.y][p.x] == EXIT)
		path = BASE EXIT_XPM;
	else if (app->game.map[p.y][p.x] == COLL)
		path = BASE COLL_XPM;
	else if (app->game.map[p.y][p.x] == ENEM)
		path = BASE ENEM_XPM;
	if (!place_img(app->mlx, app->screen.img, BASE VOID_XPM, p))
		return (NULL);
	return (path);
}

int	buildbg(t_app *app)
{
	int		i;
	int		j;
	int		ret;
	char	*path;

	(i = -1) && (ret = 1);
	while (++i < app->game.height && ret)
	{
		j = -1;
		while (++j < app->game.width && ret)
		{
			if (app->game.map[i][j] == WALL)
				path = BASE WALL_XPM;
			else if (app->game.map[i][j] == VOID)
				path = BASE VOID_XPM;
			else if (app->game.map[i][j] == EXIT || app->game.map[i][j] == COLL
					|| app->game.map[i][j] == ENEM)
				path = place_w_trans(app, (t_pos){j, i});
			ret = place_img(app->mlx, app->screen.img, path,
					(t_pos){j, i});
		}
	}
	return (ret);
}
