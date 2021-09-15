/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 22:37:17 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/15 02:44:57 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gui.h"

#include "ft_stdlib.h"

char	*get_player_img(t_app *app, int frame)
{
	if (app->game.player.dir == 1 && frame == 1)
		return (BASE PLAY_XPM PLAY_UP ONE);
	if (app->game.player.dir == 2 && frame == 1)
		return (BASE PLAY_XPM PLAY_RIGHT ONE);
	if (app->game.player.dir == 3 && frame == 1)
		return (BASE PLAY_XPM PLAY_DOWN ONE);
	if (app->game.player.dir == 4 && frame == 1)
		return (BASE PLAY_XPM PLAY_LEFT ONE);
	if (app->game.player.dir == 1 && frame == 2)
		return (BASE PLAY_XPM PLAY_UP TWO);
	if (app->game.player.dir == 2 && frame == 2)
		return (BASE PLAY_XPM PLAY_RIGHT TWO);
	if (app->game.player.dir == 3 && frame == 2)
		return (BASE PLAY_XPM PLAY_DOWN TWO);
	if (app->game.player.dir == 4 && frame == 2)
		return (BASE PLAY_XPM PLAY_LEFT TWO);
	if (app->game.player.dir == 1 && frame == 3)
		return (BASE PLAY_XPM PLAY_UP THREE);
	if (app->game.player.dir == 2 && frame == 3)
		return (BASE PLAY_XPM PLAY_RIGHT THREE);
	if (app->game.player.dir == 3 && frame == 3)
		return (BASE PLAY_XPM PLAY_DOWN THREE);
	if (app->game.player.dir == 4 && frame == 3)
		return (BASE PLAY_XPM PLAY_LEFT THREE);
	return (NULL);
}
