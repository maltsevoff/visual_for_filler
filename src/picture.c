/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:26:15 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/08 19:26:18 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	ft_put_pixel(int x, int y, t_fdf *fdf, int color)
{
	int		i;

	x += WIN_WIDTH / 2;
	y += WIN_HEIGHT / 2;
	if ((x >= 0 && x < WIN_WIDTH) && (y >= 0 && y < WIN_HEIGHT))
	{
		i = ((x * fdf->img->bpp / 8) + (y * fdf->img->size_line));
		fdf->img->addr[i] = color;
		fdf->img->addr[++i] = color >> 8;
		fdf->img->addr[++i] = color >> 16;
	}
}

void	brethen_line(t_coord p0, t_coord p1, t_fdf *game)
{
	t_coord delta;
	t_coord	sign;
	t_coord	error;

	delta.x = abs(p1.x - p0.x);
	delta.y = abs(p1.y - p0.y);
	sign.x = p0.x < p1.x ? 1 : -1;
	sign.y = p0.y < p1.y ? 1 : -1;
	error.x = delta.x - delta.y;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		ft_put_pixel(p0.x, p0.y, game, game->p1->col);
		error.y = error.x * 2;
		if (error.y > -delta.y)
		{
			error.x -= delta.y;
			p0.x += sign.x;
		}
		if (error.y < delta.x)
		{
			error.x += delta.x;
			p0.y += sign.y;
		}
	}
}

void		choose_sector(t_fdf *game, int x, int y)
{
	int		i;
	t_coord	tmp;

	i = -1;
	tmp = game->map[y][x];
	if (ft_strchr("xXoO", game->map[y][x].z))
	{
		while (tmp.y + ++i < game->map[y + 1][x].y)
		{
			brethen_line(tmp)
		}
	}
	else
	{
		if (x + 1 != game->m_x)
			brethen_line(game->map[y][x], game->map[y][x + 1], game);
		if (y + 1 != game->m_y)
			brethen_line(game->map[y][x], game->map[y + 1][x], game);
	}
}

int			make_picture(t_fdf *game)
{
	int		*i;
	int		y;
	int		x;

	i = (int *)game->img->addr;
	y = 0;
	while (y < game->m_y)
	{
		x = 0;
		while (x < game->m_x)
		{
			ft_put_pixel(game->map[y][x].x, game->map[y][x].y,
					game, game->map[y][x].color);
			choose_sector(elem, game);
			x++;
		}
		y++;
	}
	return (0);
}
