/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_and_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:10:38 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/29 21:10:39 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

size_t	w_c2(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			r++;
		s++;
	}
	return (r);
}

void	as(t_value *s0)
{
	s0->x_distance = s0->x_distance + 1;
	s0->y2 = s0->y2 + 1;
}

void	as2(t_value *s0)
{
	s0->x_distance = s0->x_distance - 1;
	s0->y2 = s0->y2 - 1;
}

void	key_end(t_value *s0)
{
	clear(s0);
	all_point_combin(s0, s0->d, &s0->img);
	mlx_put_image_to_window(s0->vars.mlx, s0->vars.mlx_win, s0->img.img, 0, 0);
}

void	close1_0(int keycode, t_value *s0)
{
	if (53 == keycode)
	{
		free1(s0);
		mlx_clear_window(s0->vars.mlx, s0->vars.mlx_win);
		mlx_destroy_image(s0->vars.mlx, s0->img.img);
		exit(1);
	}
	if (4 == keycode)
	{
		as(s0);
		key_end(s0);
	}
	if (5 == keycode)
	{
		as2(s0);
		key_end(s0);
	}
	if (45 == keycode)
	{
		s0->y2 = 0;
		key_end(s0);
	}
}
