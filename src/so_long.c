/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 00:11:32 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/13 23:21:35 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	move_p(t_vars *vars)
{
	vars->img_p.x_min = vars->img_p.x_min_tmp;
	vars->img_p.y_min = vars->img_p.y_min_tmp;
	free(vars->img_w.crds);
	free(vars->img_c.crds);
	free(vars->img_e.crds);
	mlx_clear_window(vars->mlx, vars->win);
	build_f(vars);
	build_w(vars);
	build_e(vars);
	build_c(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img_p.img,
		vars->img_p.x_min, vars->img_p.y_min);
}

static void	check_before_move_p(t_vars *vars)
{
	int			psn;
	static int	count_steps = 0;

	if (is_cross_w(vars))
	{
		vars->img_p.x_min_tmp = vars->img_p.x_min;
		vars->img_p.y_min_tmp = vars->img_p.y_min;
		return ;
	}
	ft_printf("%d step\n", ++count_steps);
	psn = is_cross_c(vars);
	if (psn)
		vars->map[psn] = '0';
	if (is_cross_e(vars) && !ft_strchr(vars->map, 'C'))
	{
		ft_printf("You won!\n");
		ft_close_esc(vars);
	}
	move_p(vars);
}

static int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 119)
		vars->img_p.y_min_tmp -= STEP;
	else if (keycode == 115)
		vars->img_p.y_min_tmp += STEP;
	else if (keycode == 97)
		vars->img_p.x_min_tmp -= STEP;
	else if (keycode == 100)
		vars->img_p.x_min_tmp += STEP;
	else if (keycode == 65307)
		ft_close_esc(vars);
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		check_before_move_p(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	errno = 0;
	if (argc != 2)
		print_error("Number of arguments is not equal to 2");
	vars.map = read_map(argv[1]);
	vars.mlx = mlx_init();
	build_f(&vars);
	build_w(&vars);
	build_e(&vars);
	build_c(&vars);
	build_p(&vars);
	mlx_mouse_hide(vars.mlx, vars.win);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 8, ft_close_mouse, &vars);
	mlx_loop(vars.mlx);
}
