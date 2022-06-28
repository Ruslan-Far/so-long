/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:09:21 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/14 12:02:40 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	create_win(t_vars *vars, int *count)
{
	int	width_map;
	int	height_map;

	vars->img_f.img = mlx_xpm_file_to_image(vars->mlx, "assets/f.xpm",
			&vars->img_f.width_img, &vars->img_f.height_img);
	width_map = get_width_map(vars->map);
	height_map = ft_strlen(vars->map) / width_map--;
	vars->width_win = width_map * vars->img_f.width_img;
	vars->height_win = height_map * vars->img_f.height_img;
	vars->win = mlx_new_window(vars->mlx, vars->width_win,
			vars->height_win, "so_long");
	(*count)++;
}

void	load_w_xpm(t_vars *vars, int *count)
{
	vars->img_w.img = mlx_xpm_file_to_image(vars->mlx, "assets/w.xpm",
			&vars->img_w.width_img, &vars->img_w.height_img);
	(*count)++;
}

void	load_e_xpm(t_vars *vars, int *count)
{
	vars->img_e.img = mlx_xpm_file_to_image(vars->mlx, "assets/e.xpm",
			&vars->img_e.width_img, &vars->img_e.height_img);
	(*count)++;
}

void	load_c_xpm(t_vars *vars, int *count)
{
	vars->img_c.img = mlx_xpm_file_to_image(vars->mlx, "assets/c.xpm",
			&vars->img_c.width_img, &vars->img_c.height_img);
	(*count)++;
}
