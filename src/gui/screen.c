/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:18:51 by mgueifao          #+#    #+#             */
/*   Updated: 2021/07/11 19:37:17 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_screen(t_screen *screen)
{
	screen->height = 768;
	screen->width = 1366;
	screen->title = ft_strdup("so_long");
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	next_frame(t_screen screen, void *mlx)
{
	t_img tmp;

	mlx_put_image_to_window(mlx, screen.win,
		screen.img[1].img, 0, 0);
	tmp = screen.img[0];
	screen.img[0] = screen.img[1];
	screen.img[1] = tmp;
}
