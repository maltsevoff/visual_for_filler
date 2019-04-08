#include "graphic.h"

void	read_map(t_fdf *game, char *line)
{

}

int		logic(t_fdf *game)
{
	char	*line;

	while (get_next_line(FD, &line))
	{
		if (ft_strstr(line, "Plateau"))
		{
			read_map(game, line);
			ft_strdel(&line);
		}
		else
			ft_strdle(&line);
	}
}
