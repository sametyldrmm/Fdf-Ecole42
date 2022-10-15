/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syildiri <syildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:40:33 by syildiri          #+#    #+#             */
/*   Updated: 2022/06/03 21:40:35 by syildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_open(t_temp_value tmp)
{
	tmp.fd = open(tmp.argvv, O_RDONLY);
	return (tmp.fd);
}

int	exit_prog(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (1);
}

int	closee(int keycode, t_vars *vars)
{
	if (keycode == 53)
		exit_prog(vars);
	return (1);
}

int	main(int argc, char **argv)
{
	t_xyz_value		*xyz;
	t_temp_value	tmp;
	t_image			img;
	t_vars			vars;

	tmp.argvv = argv[1];
	tmp.fd = ft_open(tmp);
	if ((tmp.fd) <= 0 || argc < 2)
	{
		write(1, "\nERROR: SOMETHINGS GET WRONG\n", 30);
		exit(0);
	}
	xyz = (t_xyz_value *)malloc(sizeof(t_xyz_value));
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1500, 1300, "FDF!");
	img.img = mlx_new_image(vars.mlx, 1500, 1300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	tmp = get_x_y(xyz, tmp);
	fill_z(xyz, tmp);
	draw_z(xyz, &img, tmp);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 0, closee, &vars);
	mlx_hook(vars.win, 17, 0, exit_prog, &vars);
	mlx_loop(vars.mlx);
}
