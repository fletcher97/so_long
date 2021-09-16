/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:36:28 by mgueifao          #+#    #+#             */
/*   Updated: 2021/09/16 02:30:02 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H
# define LOGIC_H

# include "so_long.h"

# define UP 1
# define LEFT 2
# define DOWN 3
# define RIGHT 4

# define SEED 123456789

void	move(t_app *app, int key_code);
void	print_end_msg(t_app *app);
void	move_enemy(t_app *app);

#endif
