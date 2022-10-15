/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:10:41 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/29 21:11:21 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	start_struct(t_value *s0, char *argv1)
{
	s0->all_x = 0;
	s0->all_y = 0;
	s0->all_z = 0;
	s0->x1 = 500;
	s0->y1 = 500;
	s0->x2 = 0;
	s0->y2 = 0;
	s0->lim_x = 0;
	s0->lim_y = 0;
	s0->x_distance = 0;
	s0->y_distance = 0;
	s0->z_multiply = 0;
	s0->a = 4;
	s0->k = 4;
	s0->string = argv1;
}

void	free0(t_value *s0)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < s0->lim_y)
	{
		free(s0->all_x[i]);
		i++;
	}
	i = 0;
	while (i < s0->lim_y -1)
	{
		free(s0->all_y[i]);
		i++;
	}
	free(s0->all_x);
	free(s0->all_y);
}

void	free1(t_value *s0)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s0->lim_y)
	{
		free(s0->all_x[i]);
		i++;
	}
	i = 0;
	while (i < s0->lim_y -1)
	{
		free(s0->all_z[i]);
		free(s0->all_y[i]);
		i++;
	}
	free(s0->all_x);
	free(s0->all_z);
	free(s0->all_y);
}
