/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:36:31 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/13 22:01:18 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	put_img_to_win_fill_crds_w(t_vars *vars, int i, int j, int *crds_index)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_w.img, j, i);
	vars->img_w.crds[*crds_index].x_min = j;
	vars->img_w.crds[*crds_index].y_min = i;
	vars->img_w.crds[*crds_index].x_max = j + vars->img_w.width_img;
	vars->img_w.crds[(*crds_index)++].y_max = i + vars->img_w.height_img;
}

void	put_img_to_win_fill_crds_e(t_vars *vars, int i, int j, int *crds_index)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_e.img, j, i);
	vars->img_e.crds[*crds_index].x_min = j;
	vars->img_e.crds[*crds_index].y_min = i;
	vars->img_e.crds[*crds_index].x_max = j + vars->img_e.width_img;
	vars->img_e.crds[(*crds_index)++].y_max = i + vars->img_e.height_img;
}

void	put_img_to_win_fill_crds_c(t_vars *vars, int i, int j, int *crds_index)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_c.img, j, i);
	vars->img_c.crds[*crds_index].x_min = j;
	vars->img_c.crds[*crds_index].y_min = i;
	vars->img_c.crds[*crds_index].x_max = j + vars->img_c.width_img;
	vars->img_c.crds[*crds_index].y_max = i + vars->img_c.height_img;
}

void	put_img_to_win_p(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_p.img, j, i);
	vars->img_p.x_min = j;
	vars->img_p.y_min = i;
	vars->img_p.x_min_tmp = vars->img_p.x_min;
	vars->img_p.y_min_tmp = vars->img_p.y_min;
}
