/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listeners.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fletcher <fletcher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:45:57 by fletcher          #+#    #+#             */
/*   Updated: 2022/03/08 22:51:18 by fletcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(LISTENERS_H)
#define LISTENERS_H

#include "so_long.h"

# define MLX_DESTROY_NOTIFY	17
# define MLX_KEY_PRESS		2
# define MLX_KEY_RELEASE	3

int		stop(void *param);
int		on_key_press(int key_code, void *param);
int		on_key_release(int key_code, void *param);
void	set_listeners(t_app *app);


#endif // LISTENERS_H
