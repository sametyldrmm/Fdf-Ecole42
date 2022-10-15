/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:32:54 by syildiri          #+#    #+#             */
/*   Updated: 2022/03/30 16:33:45 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include "get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
}	t_data;

typedef struct s_value2
{
	int		one_point_x;
	int		two_point_x;
	int		one_point_y;
	int		two_point_y;
	int		two_point_y2;
	int		two_point_x2;
	int		line_down_lenght;
	int		line_left_lenght;
	int		color;
	int		color2;
	double	distance_lenght_two_x;
	double	distance_lenght_two_y;
	double	slope;
	int		free_x;
	double	k;
	int		d;
	int		i;
	int		j;
}	t_value2;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*mlx_win;
}	t_vars;

typedef struct s_value
{
	int			x1;
	float		x2;
	int			y1;
	float		y2;
	int			**all_x;
	int			**all_y;
	int			**all_z;
	int			lim_x;
	int			lim_y;
	int			x_distance;
	int			y_distance;
	float		z_multiply;
	char		*string;
	int			d;
	int			a;
	int			k;
	int			free_varmi;
	int			i;
	t_vars		vars;
	t_data		img;
	t_value2	*s1;
	int			open_value;
}	t_value;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	left_line_pixel_put(t_data *data, t_value2 *s1, int line_lenght);
void	down_line_pixel_put(t_data *data, t_value2 *s1, int line_lenght);
void	two_point_between_line_put1(t_data *data, t_value2 *s1,
			int two_point_x, int two_point_y);
void	two_point_between_line_put(t_data *data, t_value2 *s1,
			int two_point_x, int two_point_y);
void	start_struct(t_value *s0, char *argv1);
void	x_doldur(t_value *s0, int d);
void	y_doldur(t_value *s0, int d);
void	free0(t_value *s0);
void	point_combin_st(t_value2 *s1);
void	point_combin_md(t_value2 *s1, t_value *s0);
void	point_combin(t_value *s0, int d, t_data *img, t_value2 *s1);
void	all_point_combin(t_value *s0, int d, t_data *img);
int		veri_al(t_value *s0);
size_t	w_c2(char const *s, char c);
void	detect_limit(t_value *s0);
void	as(t_value *s0);
void	as2(t_value *s0);
void	free1(t_value *s0);
void	clear(t_value *s0);
void	key_end(t_value *s0);
int		close1(int keycode, t_value *s0);
int		close2(t_value *s0);
void	close1_0(int keycode, t_value *s0);
void	close1_1(int keycode, t_value *s0);
void	close1_2(int keycode, t_value *s0);
size_t	ft_strlen(const char *s);
size_t	w_l(char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *str1, const char *str2, size_t n);
long	ft_atoi(const char *str);
size_t	w_c(char const *s, char c);
#endif
