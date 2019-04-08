/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:23:40 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/23 17:23:42 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

t_img		*open_window()
{
	t_img	*img;

	img = ft_memalloc(sizeof(img));
	img->mlx_ptr = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
					"filler");
	img->ptr = mlx_new_image(img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line,
				&img->endian);
	return (img);
}

void		set_player(char *line, char *player)
{
	line = ft_strrchr(line, '/');
	player = ft_strnew(ft_strchr(line, '.') - line);
	player = ft_strncpy(player, line, ft_strchr(line, '.') - line);
}

void		read_players(t_fdf *game)
{
	char	*line;

	while (get_next_line(FD, &line) > 0)
	{
		if (ft_strstr(line, "exec p1"))
		{
			set_player(line, game->p1);
		}
		else if (ft_strstr(line, "exec p2"))
		{
			set_player(line, game->p2);
			ft_strdel(&line);
			return ;
		}
		ft_strdel(&line);
	}
}

int			main(void)
{
	t_fdf	*game;

	game = ft_memalloc(sizeof(t_fdf));
	game->img = open_window();
	read_players(game);
	while (1)
	{
		if (logic(game) == 0)
			exit (0);
	}
	mlx_loop(game->img->mlx_ptr);
	return (0);
}
