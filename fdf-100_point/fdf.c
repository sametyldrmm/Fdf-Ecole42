/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:39:58 by syildiri          #+#    #+#             */
/*   Updated: 2022/06/03 21:40:00 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_z(t_xyz_value *xyz, t_temp_value tmp)
{
	while (tmp.rwnmbrtemp > 0)
	{
		xyz->y = get_next_line(tmp.fd);
		tmp.temp = ft_split(xyz->y, ' ');
		xyz->z[tmp.i] = (int *)malloc(xyz->columnnumber * sizeof(int));
		while (tmp.clmnmbrtemp > 0)
		{
			xyz->z[tmp.i][tmp.j] = ft_atoi(tmp.temp[tmp.j]);
			tmp.j++;
			tmp.clmnmbrtemp--;
		}
		tmp.j = 0;
		tmp.clmnmbrtemp = xyz->columnnumber;
		while (tmp.temp[tmp.j])
			free(tmp.temp[tmp.j++]);
		tmp.j = 0;
		free(tmp.temp);
		tmp.temp = 0;
		free(xyz->y);
		tmp.i++;
		tmp.rwnmbrtemp--;
	}
	free(tmp.temp);
	close(tmp.fd);
}

t_temp_value	get_x_y(t_xyz_value *xyz, t_temp_value tmp)
{
	start_struct(xyz);
	xyz->y = get_next_line(tmp.fd);
	xyz->columnnumber = w_c(xyz->y, ' ');
	while (xyz->y != NULL)
	{
		xyz->rownumber++;
		free(xyz->y);
		xyz->y = get_next_line(tmp.fd);
	}
	free(xyz->y);
	close(tmp.fd);
	tmp.fd = ft_open(tmp);
	xyz->z = (int **)malloc(xyz->rownumber * sizeof(int *));
	tmp.rwnmbrtemp = xyz->rownumber;
	tmp.clmnmbrtemp = xyz->columnnumber;
	return (tmp);
}

void	start_struct(t_xyz_value *xyz)
{
	xyz->columnnumber = 0;
	xyz->rownumber = 0;
	xyz->y = 0;
	xyz->z = 0;
	xyz->x_start = 0;
	xyz->y_start = 600;
	xyz->x_copy_start = 0;
	xyz->y_copy_start = 600;
}

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < 1500 && y < 1500)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	bresenham(t_image *img, t_brshm_value brm)
{
	brm.x = (brm.x1 - brm.x0);
	brm.y = (brm.y1 - brm.y0);
	brm.maxx = max(abs((int)brm.x), abs((int)brm.y));
	brm.x_inc = brm.x / brm.maxx;
	brm.y_inc = brm.y / brm.maxx;
	while ((int)brm.maxx--)
	{	
		my_mlx_pixel_put(img, brm.x0, brm.y0, img->color);
		brm.x0 += brm.x_inc;
		brm.y0 += brm.y_inc;
	}
}
