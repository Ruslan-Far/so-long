/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:39:38 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/14 12:37:32 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	build_f(t_vars *vars)
{
	int			i;
	int			j;
	static int	count = 0;

	if (count == 0)
		create_win(vars, &count);
	i = 0;
	while (i < vars->height_win)
	{
		j = 0;
		while (j < vars->width_win)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img_f.img, j, i);
			j += vars->img_f.width_img;
		}
		i += vars->img_f.height_img;
	}
}

void	build_w(t_vars *vars)
{
	int			i;
	int			j;
	int			k;
	int			crds_index;
	static int	count = 0;

	if (count == 0)
		load_w_xpm(vars, &count);
	init_w(vars, &i, &k, &crds_index);
	while (i < vars->height_win)
	{
		j = 0;
		while (j < vars->width_win)
		{
			if (vars->map[k++] == '1')
				put_img_to_win_fill_crds_w(vars, i, j, &crds_index);
			j += vars->img_w.width_img;
		}
		i += vars->img_w.height_img;
		k++;
	}
}

void	build_e(t_vars *vars)
{
	int			i;
	int			j;
	int			k;
	int			crds_index;
	static int	count = 0;

	if (count == 0)
		load_e_xpm(vars, &count);
	init_e(vars, &i, &k, &crds_index);
	while (i < vars->height_win)
	{
		j = 0;
		while (j < vars->width_win)
		{
			if (vars->map[k++] == 'E')
				put_img_to_win_fill_crds_e(vars, i, j, &crds_index);
			j += vars->img_e.width_img;
		}
		i += vars->img_e.height_img;
		k++;
	}
}

void	build_c(t_vars *vars)
{
	int			i;
	int			j;
	int			k;
	int			crds_index;
	static int	count = 0;

	if (count == 0)
		load_c_xpm(vars, &count);
	init_c(vars, &i, &k, &crds_index);
	while (i < vars->height_win)
	{
		j = 0;
		while (j < vars->width_win)
		{
			if (vars->map[k++] == 'C')
			{
				put_img_to_win_fill_crds_c(vars, i, j, &crds_index);
				vars->img_c.crds[crds_index++].psn = k - 1;
			}
			j += vars->img_c.width_img;
		}
		i += vars->img_c.height_img;
		k++;
	}
}

void	build_p(t_vars *vars)
{
	int	i;
	int	j;
	int	k;

	vars->img_p.img = mlx_xpm_file_to_image(vars->mlx, "assets/p.xpm",
			&vars->img_p.width_img, &vars->img_p.height_img);
	i = 0;
	k = 0;
	while (i < vars->height_win)
	{
		j = 0;
		while (j < vars->width_win)
		{
			if (vars->map[k++] == 'P')
			{
				put_img_to_win_p(vars, i, j);
				break ;
			}
			j += vars->img_p.width_img;
		}
		i += vars->img_p.height_img;
		k++;
	}
}
