/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:50:48 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/13 21:54:51 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_ints(int *i, int *k, int *crds_index)
{
	*i = 0;
	*k = 0;
	*crds_index = 0;
}

void	init_w(t_vars *vars, int *i, int *k, int *crds_index)
{
	vars->img_w.crds = malloc(sizeof(t_crds) * (ft_strlen(vars->map) + 1));
	ft_bzero_crds(vars->img_w.crds, ft_strlen(vars->map) + 1);
	init_ints(i, k, crds_index);
}

void	init_e(t_vars *vars, int *i, int *k, int *crds_index)
{
	vars->img_e.crds = malloc(sizeof(t_crds) * (ft_strlen(vars->map) + 1));
	ft_bzero_crds(vars->img_e.crds, ft_strlen(vars->map) + 1);
	init_ints(i, k, crds_index);
}

void	init_c(t_vars *vars, int *i, int *k, int *crds_index)
{
	vars->img_c.crds = malloc(sizeof(t_crds) * (ft_strlen(vars->map) + 1));
	ft_bzero_crds(vars->img_c.crds, ft_strlen(vars->map) + 1);
	init_ints(i, k, crds_index);
}
