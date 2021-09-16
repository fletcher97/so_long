/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:19:34 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/16 00:46:06 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	char	*title;
	t_img	*img;
}				t_screen;

typedef struct s_player
{
	int	x;
	int	y;
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
	t_screen	screen;
	t_game		game;
}				t_app;

#endif
