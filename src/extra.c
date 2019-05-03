/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:48:49 by omaltsev          #+#    #+#             */
/*   Updated: 2019/04/08 16:48:51 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void	free_map(char **map)
{
	int		i;

	i = 0;
	if (map[i] == NULL)
		return ;
	while (map[i])
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	if (map != NULL)
		free(map);
}

void	end_game(t_fdf *game, char *line)
{
	char	**map;

	map = ft_strsplit(line, ' ');
	game->p1->score = ft_atoi(map[3]);
	free_map(map);
	get_next_line(g_fd, &line);
	map = ft_strsplit(line, ' ');
	game->p2->score = ft_atoi(map[3]);
}

void	check_score(t_fdf *game)
{
	if (game->p1->score > game->p2->score)
	{
		printf("WIN 1 !!!!!!!! %s\n", game->p1->name);
		mlx_string_put(game->img->mlx_ptr, game->img->mlx_win, 450, 800,
			game->p1->col, "Player 1 WIN");
	}
	else if (game->p1->score < game->p2->score)
	{
		printf("WIN 2 !!!!!!!! %s\n", game->p2->name);
		mlx_string_put(game->img->mlx_ptr, game->img->mlx_win, 450, 800,
			game->p2->col, "Player 2 WIN");
	}
	else
	{
		printf("EQUAL SCORE !!!!!!!!\n");
		mlx_string_put(game->img->mlx_ptr, game->img->mlx_win, 450, 800,
			WHITE, "EQUAL SCORE");
		if (game->p1->score == 0 && game->p2->score == 0)
			mlx_string_put(game->img->mlx_ptr, game->img->mlx_win, 450, 850,
				WHITE, "invalid map");
	}
}
