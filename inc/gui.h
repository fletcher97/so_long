/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 23:41:56 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/15 02:55:17 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "so_long.h"

# define IMG_SIZE 32
# define SPEED 80

# if IMG_SIZE==16
#  define BASE "./res/assets/16/"
# elif IMG_SIZE==32
#  define BASE "./res/assets/32/"
# elif IMG_SIZE==64
#  define BASE "./res/assets/64/"
# elif IMG_SIZE==128
#  define BASE "./res/assets/128/"
# endif

# define VOID_XPM "background.xpm"
# define WALL_XPM "wall.xpm"
# define EXIT_XPM "exit.xpm"
# define COLL_XPM "fish.xpm"
# define PLAY_XPM "player"

# define ONE "1.xpm"
# define TWO "2.xpm"
# define THREE "3.xpm"

# define PLAY_UP "_up_"
# define PLAY_DOWN "_down_"
# define PLAY_LEFT "_left_"
# define PLAY_RIGHT "_right_"

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

void	get_screen(t_app *app);
void	render(t_app *app, int fcount);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		buildbg(t_app *app);
void	next_frame(t_screen screen, void *mlx);
int		place_img(void *mlx, t_img *dst, char *path, t_pos p);
char	*get_player_img(t_app *app, int frame);

#endif
