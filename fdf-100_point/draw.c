/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:40:12 by syildiri          #+#    #+#             */
/*   Updated: 2022/06/03 21:40:13 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_color(int i, int j, t_xyz_value *xyz, t_image *img)
{
	if (xyz->z[i][j] < 10 && xyz->z[i][j] > 0)
		img->color = 0x00c41005;
	else if (xyz->z[i][j] <= 40 && xyz->z[i][j] > 10)
		img->color = 0x00ff1a1a;
	else if (xyz->z[i][j] <= 60 && xyz->z[i][j] > 40)
		img->color = 0x00ff8080;
	else if (xyz->z[i][j] <= 70 && xyz->z[i][j] > 60)
		img->color = 0x00ffb3b3;
	else if (xyz->z[i][j] <= 100 && xyz->z[i][j] > 70)
		img->color = 0x00FFFFFF;
	else
		img->color = 0x00c41005;
}

void	get_way(int i, int j, t_xyz_value *xyz, t_image *img)
{
	t_brshm_value	brm;

	brm.a = xyz->z2;
	brm.x0 = xyz->x_start;
	brm.x1 = (xyz->x_start + xyz->x_row_inc);
	brm.y0 = xyz->y_start - xyz->z[i][j] * brm.a;
	brm.y1 = (xyz->y_start + xyz->y_row_inc) - xyz->z[i][j + 1] * brm.a;
	if (xyz->rownumber > 100)
	{
		get_color(i, j, xyz, img);
		bresenham(img, brm);
		brm.y1 = (xyz->y_start + xyz->y_col_inc) - xyz->z[i + 1][j] * brm.a;
		bresenham(img, brm);
	}
	if (xyz->rownumber <= 100)
	{
		img->color = 1006 * xyz->z[i][j] + 0x00FFFFFF + 1006 * xyz->z[i][j + 1];
		bresenham(img, brm);
		img->color = 1006 * xyz->z[i][j] + 0x00FFFFFF + 1006 * xyz->z[i + 1][j];
		brm.y1 = (xyz->y_start + xyz->y_col_inc) - xyz->z[i + 1][j] * brm.a;
		bresenham(img, brm);
	}
}

void	calculate_increment(t_xyz_value *xyz)
{
	if (xyz->rownumber < 100)
	{
		xyz->y_row_inc = -(232 / xyz->rownumber);
		xyz->x_row_inc = (500 / xyz->columnnumber);
		xyz->x_col_inc = (500 / xyz->columnnumber);
		xyz->y_col_inc = (232 / xyz->columnnumber);
	}
	if (xyz->rownumber >= 100)
	{
		xyz->y_row_inc = -0.65;
		xyz->x_row_inc = 1.625;
		xyz->x_col_inc = 1.3;
		xyz->y_col_inc = 0.65;
	}
	xyz->z2 = (xyz->columnnumber / xyz->rownumber) * 2;
	if (xyz->rownumber < 20)
		xyz->z2 = xyz->z2 * 2;
}

void	draw_z(t_xyz_value *xyz, t_image *img, t_temp_value tmp)
{
	calculate_increment(xyz);
	while (tmp.i < xyz->rownumber - 1)
	{
		xyz->x_start = xyz->x_copy_start;
		xyz->y_start = xyz->y_copy_start;
		tmp.j = 0;
		while (tmp.j < xyz->columnnumber - 1)
		{
			get_way(tmp.i, tmp.j, xyz, img);
			xyz->x_start += xyz->x_row_inc;
			xyz->y_start += xyz->y_row_inc;
			tmp.j++;
		}
		xyz->x_copy_start += xyz->x_col_inc;
		xyz->y_copy_start += xyz->y_col_inc;
		tmp.i++;
	}
}

float	max(int a, int b)
{
	if (a > b)
		return ((float)(a));
	else
		return ((float)(b));
}
