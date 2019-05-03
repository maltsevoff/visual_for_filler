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

	img = (t_img *)ft_memalloc(sizeof(t_img));
	img->mlx_ptr = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
					"filler");
	img->ptr = mlx_new_image(img->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line,
				&img->endian);
	return (img);
}

char		*set_player_name(char *line)
{
	char	*name;

	line = ft_strrchr(line, '/') + 1;
	name = ft_strnew(ft_strchr(line, '.') - line);
	name = ft_strncpy(name, line, ft_strchr(line, '.') - line);
	return (name);
}

void		read_players(t_fdf *game)
{
	char	*line;

	game->p1 = ft_memalloc(sizeof(t_player));
	game->p2 = ft_memalloc(sizeof(t_player));
	while (get_next_line(g_fd, &line) > 0)
	{
		if (ft_strstr(line, "exec p1"))
		{
			game->p1->name = set_player_name(line);
			game->p1->col = 0x0000FF;
		}
		else if (ft_strstr(line, "exec p2"))
		{
			game->p2->name = set_player_name(line);
			ft_strdel(&line);
			game->p2->col = 0xFF0000;
			return ;
		}
		ft_strdel(&line);
	}
}

int			main(void)
{
	t_fdf	*game;

	g_fd = 0;
	game = ft_memalloc(sizeof(t_fdf));
	game->img = open_window();
	key_init(game);
	read_players(game);
	printf("map: y: %d x: %d\n", game->m_y, game->m_x);
	logic(game);
	return (0);
}
