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
	get_next_line(FD, &line);
	map = ft_strsplit(line, ' ');
	game->p2->score = ft_atoi(map[3]);
}

void	check_score(t_fdf *game)
{
	if (game->p1->score > game->p2->score)
	{
		printf("WIN 1 !!!!!!!!\n");
	}
	else if (game->p1->score < game->p2->score)
	{
		printf("WIN 2 !!!!!!!!\n");
	}
	else
	{
		printf("EQUAL SCORE !!!!!!!!\n");
	}
}
