/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:19:34 by mgueifao          #+#    #+#             */
/*   Updated: 2022/03/08 22:50:04 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <time.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
}				t_img;

typedef struct s_screen
{
	void	*win;
	int		width;
	int		height;
	int		frame_count;
	char	*title;
	t_img	*img;
}				t_screen;

typedef struct s_player
{
	int	x;
	int	y;
	int	x_mov;
	int	y_mov;
	int	dir;
	int	dead;
}				t_entit;

typedef struct s_game
{
	int			width;
	int			height;
	int			coll_left;
	int			steps;
	char		**map;
	t_entit		player;
	int			en_count;
	t_entit		*enemy;
}				t_game;

typedef struct s_app
{
	void		*mlx;
	clock_t		last_tick;
	t_screen	screen;
	t_game		game;
}				t_app;

void	terminate(t_app *app, int i);
int		stop_hook(void *param);

#endif
