/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:10:32 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/15 14:10:38 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "graphic.h"

static int		end(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

static int		select_key(int keycode)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

void			key_init(t_fdf *game)
{
	mlx_hook(game->img->mlx_win, 17, X_MASK, end, game);
	mlx_hook(game->img->mlx_win, 2, X_MASK, select_key, game);
}
