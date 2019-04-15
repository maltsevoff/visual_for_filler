/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:48:38 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/08 16:48:40 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	malloc_map(t_fdf *game, char *line)
{
	int		y;
	char	**str;

	y = 0;
	str = ft_strsplit(line, ' ');
	game->m_y = ft_atoi(str[1]);
	game->m_x = ft_atoi(str[2]);
	free_map(str);
	game->map = (t_coord **)ft_memalloc(sizeof(t_coord *) * game->m_y);
	while (y < game->m_y)
	{
		game->map[y] = (t_coord *)ft_memalloc(sizeof(t_coord) * game->m_x);
		y++;
	}
}

void	read_map(t_fdf *game, char *line)
{
	static int	flag = 0;
	int			i;
	int			x;
	char		**map;
	int			mult;

	i = -1;
	mult = 30;
	if (flag == 0)
		malloc_map(game, line);
	ft_strdel(&line);
	get_next_line(FD, &line);
	ft_strdel(&line);
	while (++i < game->m_y)
	{
		get_next_line(FD, &line);
		map = ft_strsplit(line, ' ');
		x = -1;
		while (++x < game->m_x)
		{
			game->map[i][x].x = (x - (game->m_x / 2)) * mult;
			game->map[i][x].y = (i - (game->m_y / 2)) * mult;
			game->map[i][x].z = map[1][x];
		}
		free_map(map);
		ft_strdel(&line);
	}
	flag = 1;
}

void	show_map(t_fdf *game)
{
	int		y;
	int		x;

	y = -1;
	printf("player1: %s | player2: %s\n", game->p1->name, game->p2->name);
	while (++y < game->m_y)
	{
		x = -1;
		while (++x < game->m_x)
		{
			printf("%d %d %c\n", game->map[y][x].y, game->map[y][x].x, game->map[y][x].z);
		}
	}
}

int		logic(t_fdf *game)
{
	char		*line;

	while (get_next_line(FD, &line) > 0)
	{
		// printf("%s\n", line);
		if (ft_strstr(line, "Plateau"))
		{
			printf("in logic 1\n");
			read_map(game, line);
			printf("in logic 2\n");
			make_picture(game);
			printf("in logic 3\n");
			mlx_put_image_to_window(game->img->mlx_ptr, game->img->mlx_win, game->img->ptr, 0, 0);
			printf("in logic 4\n");
			mlx_destroy_image(game->img->mlx_ptr, game->img->ptr);
			printf("in logic 5\n");
			// mlx_do_sync(game->img->mlx_ptr);
			printf("in logic 6\n");

		}
		else if (ft_strstr(line, "fin"))
		{
			end_game(game, line);
			check_score(game);
			exit(0);
		}
		else
			ft_strdel(&line);
	}
	mlx_loop(game->img->mlx_ptr);
	return (0);
}
