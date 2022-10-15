/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:10:51 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/29 21:10:52 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	left_line_pixel_put(t_data *data, t_value2 *s1, int line_lenght)
{
	int	i;

	i = 0;
	while (i++ <= line_lenght && s1->one_point_x > 0 && s1->one_point_y > 0)
	{
		my_mlx_pixel_put(data, s1->one_point_x + i,
			s1->one_point_y, s1->color2);
	}
}

void	down_line_pixel_put(t_data *data, t_value2 *s1, int line_lenght)
{
	int	i;

	i = 0;
	while (i++ <= line_lenght && s1->one_point_x > 0 && s1->one_point_y > 0)
	{
		my_mlx_pixel_put(data, s1->one_point_x,
			s1->one_point_y + i, s1->color2);
	}
}

void	two_point_between_line_put1(t_data *data, t_value2 *s1,
			int two_point_x, int two_point_y)
{
	s1->distance_lenght_two_x = (s1->one_point_x - two_point_x);
	s1->distance_lenght_two_y = (s1->one_point_y - two_point_y);
	s1->color2 = 0x00FF0000;
	if (s1->distance_lenght_two_x == 0)
	{
		if (two_point_y > s1->one_point_y)
			down_line_pixel_put(data, s1, abs(two_point_y - s1->one_point_y));
	}
	if (s1->distance_lenght_two_y == 0)
	{
		s1->one_point_y = two_point_y;
		if (two_point_x > s1->one_point_x)
			down_line_pixel_put(data, s1, abs(two_point_y - s1->one_point_y));
	}
	s1->slope = s1->distance_lenght_two_y / s1->distance_lenght_two_x;
	s1->free_x = s1->one_point_x;
	s1->k = 1;
}

void	two_point_between_line_put(t_data *data, t_value2 *s1,
			int two_point_x, int two_point_y)
{
	int	i;

	i = 0;
	data->color = s1->color;
	two_point_between_line_put1(data, s1, two_point_x, two_point_y);
	if (s1->one_point_x >= two_point_x)
	{
		while (s1->one_point_x - i++ >= two_point_x && s1->one_point_x > 0)
		{
			my_mlx_pixel_put(data, s1->one_point_x - i,
				s1->one_point_y + round(-i * s1->slope), s1->color);
			s1->d = 0;
			s1->d = round(s1->one_point_y + (-i * s1->slope));
		}
	}
	else
	{
		while (s1->one_point_x + i++ <= two_point_x)
		{
			my_mlx_pixel_put(data, s1->one_point_x + i,
				s1->one_point_y + round(i * s1->slope), s1->color);
			s1->d = 0;
			s1->d = round(s1->one_point_y + (i * s1->slope));
		}
	}
}
