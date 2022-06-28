/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 22:13:48 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/13 22:25:02 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close_esc(t_vars *vars)
{
	free(vars->img_w.crds);
	free(vars->img_c.crds);
	free(vars->img_e.crds);
	free(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	ft_close_mouse(t_vars *vars)
{
	free(vars->img_w.crds);
	free(vars->img_c.crds);
	free(vars->img_e.crds);
	free(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
