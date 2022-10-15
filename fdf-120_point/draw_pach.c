/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pach.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:10:53 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/29 21:11:00 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	point_combin_st(t_value2 *s1)
{
	s1->i = 0;
	s1->j = 0;
	s1->color = 0x00FF0000;
}

void	point_combin_md(t_value2 *s1, t_value *s0)
{		
	s1->one_point_x = s0->all_x[s1->i][s1->j];
	s1->one_point_y = s0->all_y[s1->i][s1->j];
	s1->two_point_x = s0->all_x[s1->i][s1->j + 1];
	s1->two_point_x2 = s0->all_x[s1->i + 1][s1->j];
	s1->two_point_y = s0->all_y[s1->i][s1->j + 1];
	s1->two_point_y2 = s0->all_y[s1->i + 1][s1->j];
}

void	point_combin(t_value *s0, int d, t_data *img, t_value2 *s1)
{	
	y_doldur(s0, d);
	x_doldur(s0, d);
	point_combin_st(s1);
	while (s1->i < s0->lim_y -2)
	{
		while (s1->j < s0->lim_x -2)
		{
			if (s0->d < 21 && s0->all_z[s1->i][s1->j] > 0)
				s1->color = 0x00FF0000 +100000;
			else if (s0->all_z[s1->i][s1->j] && s0->d >= 20)
				s1->color = 0x00FF0000 + 1000 * s0->all_z[s1->i][s1->j];
			else
				s1->color = 0x00FF0000 ;
			point_combin_md(s1, s0);
			two_point_between_line_put(img, s1, s1->two_point_x,
				s1->two_point_y);
			two_point_between_line_put(img, s1, s1->two_point_x2,
				s1->two_point_y2);
			s1->j++;
		}
		s1->j = 0;
		s1->i++;
		if (s1->i == d - 1)
			s1->i++;
	}
}

void	all_point_combin(t_value *s0, int d, t_data *img)
{
	t_value2	*s1;

	s1 = (t_value2 *)malloc(sizeof(t_value2));
	point_combin(s0, d, img, s1);
	free(s1);
}

void	clear(t_value *s0)
{
	int	i;
	int	j;

	i = 2000;
	j = 2000;
	while (i)
	{
		j = 2000;
		while (j--)
			my_mlx_pixel_put(&s0->img, i, j, 0);
		i--;
	}
}
