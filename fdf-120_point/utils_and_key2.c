/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_key2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:10:35 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/29 21:10:37 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close1_1(int keycode, t_value *s0)
{
	if (2 == keycode)
	{
		s0->x2 += 1;
		key_end(s0);
	}
	if (0 == keycode)
	{
		s0->x2 -= 1;
		key_end(s0);
	}
	if (14 == keycode)
	{
		if (s0->a % s0->k < 4)
			s0->y2--;
		key_end(s0);
	}
	if (1 == keycode)
	{
		s0->y2 += 1;
		key_end(s0);
	}
}

void	close1_2(int keycode, t_value *s0)
{
	if (38 == keycode)
	{
		s0->z_multiply *= -1;
		s0->y2 *= -1;
		s0->x2 *= -1;
		key_end(s0);
	}
	if (18 == keycode)
	{
		s0->z_multiply += 0.2;
		key_end(s0);
	}
	if (19 == keycode)
	{
		if (s0->z_multiply > 0)
			s0->z_multiply -= 0.2;
		key_end(s0);
	}
	if (20 == keycode)
	{
		s0->x1 -= 2;
		key_end(s0);
	}
}

int	close1(int keycode, t_value *s0)
{
	close1_0(keycode, s0);
	close1_1(keycode, s0);
	close1_2(keycode, s0);
	if (21 == keycode)
	{
		s0->x1 += 2;
		key_end(s0);
	}
	if (22 == keycode)
	{
		s0->y1 += 2;
		key_end(s0);
	}
	if (23 == keycode)
	{
		s0->y1 -= 2;
		key_end(s0);
	}
	return (0);
}

int	close2(t_value *s0)
{
	free1(s0);
	mlx_clear_window(s0->vars.mlx, s0->vars.mlx_win);
	mlx_destroy_image(s0->vars.mlx, s0->img.img);
	exit(1);
}
