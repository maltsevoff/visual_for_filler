/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:27:28 by omaltsev          #+#    #+#             */
/*   Updated: 2019/03/23 17:27:30 by omaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# define WIN_HEIGHT 1000
# define WIN_WIDTH 1000

# define FD 0

# define WHITE 0xFFFFFF

# define ESC 53

# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct	s_coord
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_coord;

typedef struct	s_img
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*ptr;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_fdf
{
	t_img			*img;
	int				m_y;
	int				m_x;
	t_coord			**map;
	char			*p1;
	char			*p2;
}				t_fdf;

int				logic(t_fdf *game);

void			free_map(char **map);

#endif
