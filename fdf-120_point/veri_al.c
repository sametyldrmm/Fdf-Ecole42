/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   veri_al.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:10:32 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/29 21:10:34 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	z_doldur(t_value *s0, char ***b, int d)
{
	int	j;

	j = 0;
	s0->i = 0;
	s0->all_z = (int **)malloc((s0->lim_y) * sizeof(int *));
	while (b[s0->i][j] && s0->i < s0->lim_y)
	{
		s0->all_z[s0->i] = (int *)malloc((s0->lim_x) * (sizeof(int)));
		while (j < s0->lim_x && b[s0->i][j] != "\n")
		{
			s0->all_z[s0->i][j] = ft_atoi(b[s0->i][j]);
			free(b[s0->i][j]);
			j++;
		}
		j = 0;
		if (s0->i == s0->lim_y - 1)
		{
			free(b[s0->i]);
			free(b);
			return ;
		}
		free(b[s0->i]);
		s0->i++;
	}
}

void	x_doldur(t_value *s0, int d)
{
	int	j;

	j = 0;
	s0->i = 0;
	s0->all_x = (int **)malloc(sizeof(int *) * s0->lim_y);
	s0->a = s0->x1;
	while (s0->i < s0->lim_y)
	{
		s0->x1 += s0->x2;
		s0->all_x[s0->i] = (int *)malloc(s0->lim_x * 4);
		while (j < s0->lim_x)
		{
			s0->all_x[s0->i][j] = s0->x1 + (j * s0->x_distance);
			j++;
		}
		j = 0;
		s0->i++;
	}
	s0->x1 = s0->a;
}

void	y_doldur(t_value *s0, int d)
{
	int	j;

	j = 0;
	s0->i = 0;
	s0->a = s0->y1;
	s0->all_y = (int **)malloc(sizeof(int *) * s0->lim_y);
	while (s0->i < s0->lim_y)
	{
		s0->y1 += s0->y2;
		s0->all_y[s0->i] = (int *)malloc(s0->lim_x * 4);
		while (j < s0->lim_x)
		{
			s0->all_y[s0->i][j] = s0->y1 - s0->all_z[s0->i][j] * s0->z_multiply;
			j++;
		}
		j = 0;
		s0->i++;
		if (s0->i == s0->lim_y - 1)
		{
			s0->y1 = s0->a;
			return ;
		}
	}
}

int	veri_al(t_value *s0)
{
	int		fd;
	char	*a;
	char	***b;
	int		i;

	i = 0;
	fd = open(s0->string, O_RDONLY);
	a = get_next_line(fd);
	b = (char ***)malloc((s0->lim_y) * (sizeof(char **)));
	while (a)
	{
		b[i] = ft_split(a, ' ');
		if (a)
			free(a);
		a = get_next_line(fd);
		i++;
	}
	if (a)
		free(a);
	z_doldur(s0, b, i);
	return (i);
}

void	detect_limit(t_value *s0)
{
	int		kd;
	char	*a;

	kd = open(s0->string, O_RDONLY);
	a = get_next_line(kd);
	s0->lim_x = w_c2(a, ' ');
	s0->lim_y = 0;
	while (a)
	{
		free(a);
		a = get_next_line(kd);
		s0->lim_y++;
	}
	free(a);
}
