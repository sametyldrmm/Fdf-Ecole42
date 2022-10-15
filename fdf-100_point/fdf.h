/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:40:16 by syildiri          #+#    #+#             */
/*   Updated: 2022/06/03 21:40:17 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "minilibx_macos/mlx.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
}	t_image;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_xyz_value
{
	char	*y;
	int		**z;
	int		rownumber;
	int		columnnumber;
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	float	deltax;
	float	deltay;
	float	x_start;
	float	y_start;
	float	x_copy_start;
	float	y_copy_start;
	float	y_row_inc;
	float	x_row_inc;
	float	x_col_inc;
	float	y_col_inc;
	int		z2;

}	t_xyz_value;

typedef struct s_brshm_value
{
	float	x0;
	float	x1;
	float	y0;
	float	y1;
	float	x;
	float	y;
	float	maxx;
	float	x_inc;
	float	y_inc;
	int		a;
	int		i;
	int		j;
}	t_brshm_value;

typedef struct s_temp_value
{
	char	**temp;
	char	*argvv;
	int		i;
	int		j;
	int		rwnmbrtemp;
	int		clmnmbrtemp;
	int		fd;

}	t_temp_value;

char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
void			fill_z(t_xyz_value *xyz, t_temp_value tmp); //bi kere patlamıştı
t_temp_value	get_x_y(t_xyz_value *xyz, t_temp_value tmp);
void			start_struct(t_xyz_value *xyz);
void			my_mlx_pixel_put(t_image *data, int x, int y, int color);
void			bresenham(t_image *img, t_brshm_value brm);
void			draw_z(t_xyz_value *xyz, t_image *img, t_temp_value tmp);
int				ft_open(t_temp_value tmp);
size_t			w_c(char const *s, char c);
float			max(int a, int b);

#endif