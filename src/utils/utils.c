/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:43:05 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/13 21:06:15 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_bzero_crds(t_crds *crds, int len)
{
	int	i;

	i = 0;
	while (i < len)
		crds[i++].x_min = -1;
}

int	get_width_map(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (++i);
}

int	is_cross_w(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->img_w.crds[i].x_min != -1)
	{
		if (vars->img_p.x_min_tmp == vars->img_w.crds[i].x_min
			&& vars->img_p.y_min_tmp == vars->img_w.crds[i].y_min
			&& vars->img_p.x_min_tmp + vars->img_p.width_img
			== vars->img_w.crds[i].x_max
			&& vars->img_p.y_min_tmp + vars->img_p.height_img
			== vars->img_w.crds[i].y_max)
			return (1);
		i++;
	}
	return (0);
}

int	is_cross_c(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->img_c.crds[i].x_min != -1)
	{
		if (vars->img_p.x_min_tmp == vars->img_c.crds[i].x_min
			&& vars->img_p.y_min_tmp == vars->img_c.crds[i].y_min
			&& vars->img_p.x_min_tmp + vars->img_p.width_img
			== vars->img_c.crds[i].x_max
			&& vars->img_p.y_min_tmp + vars->img_p.height_img
			== vars->img_c.crds[i].y_max)
			return (vars->img_c.crds[i].psn);
		i++;
	}
	return (0);
}

int	is_cross_e(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->img_e.crds[i].x_min != -1)
	{
		if (vars->img_p.x_min_tmp == vars->img_e.crds[i].x_min
			&& vars->img_p.y_min_tmp == vars->img_e.crds[i].y_min
			&& vars->img_p.x_min_tmp + vars->img_p.width_img
			== vars->img_e.crds[i].x_max
			&& vars->img_p.y_min_tmp + vars->img_p.height_img
			== vars->img_e.crds[i].y_max)
			return (1);
		i++;
	}
	return (0);
}
