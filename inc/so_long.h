/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljaehaer <ljaehaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 00:11:20 by ljaehaer          #+#    #+#             */
/*   Updated: 2022/02/13 22:25:00 by ljaehaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define STEP 80

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

char	*get_next_line(int fd);
int		ft_printf(const char *src, ...);

typedef struct s_crds
{
	int		x_min;
	int		y_min;
	int		x_max;
	int		y_max;
	int		psn;
}					t_crds;

typedef struct s_f
{
	void	*img;
	int		width_img;
	int		height_img;
}					t_f;

typedef struct s_w
{
	void	*img;
	int		width_img;
	int		height_img;
	t_crds	*crds;
}					t_w;

typedef struct s_e
{
	void	*img;
	int		width_img;
	int		height_img;
	t_crds	*crds;
}					t_e;

typedef struct s_c
{
	void	*img;
	int		width_img;
	int		height_img;
	t_crds	*crds;
}					t_c;

typedef struct s_p
{
	void	*img;
	int		width_img;
	int		height_img;
	int		x_min;
	int		y_min;
	int		x_min_tmp;
	int		y_min_tmp;
}					t_p;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		width_win;
	int		height_win;
	char	*map;
	t_f		img_f;
	t_w		img_w;
	t_e		img_e;
	t_c		img_c;
	t_p		img_p;
}					t_vars;

void	print_error(char *error);
void	print_error_with_free(char *error, char *map);
void	print_error_with_free2(char *error, char *map, char *line);
void	check_extension_fmap(char *file_map);
void	check_access_fmap(int *fd, char *file_map);

void	process_first_str(char *map, char *line);
void	process_last_str(char *map, int *count_chars);
void	check_rectangular_map(char *map, char *line);
void	check_valid_chars(char *map, char *line);
char	*search_penult_nl(char *map);

void	check_on_other_chars(char *map, char *line);

void	ft_bzero_crds(t_crds *crds, int len);
int		get_width_map(char *map);
int		is_cross_w(t_vars *vars);
int		is_cross_c(t_vars *vars);
int		is_cross_e(t_vars *vars);

void	create_win(t_vars *vars, int *count);
void	load_w_xpm(t_vars *vars, int *count);
void	load_e_xpm(t_vars *vars, int *count);
void	load_c_xpm(t_vars *vars, int *count);

void	put_img_to_win_fill_crds_w(t_vars *vars, int i, int j, int *crds_index);
void	put_img_to_win_fill_crds_e(t_vars *vars, int i, int j, int *crds_index);
void	put_img_to_win_fill_crds_c(t_vars *vars, int i, int j, int *crds_index);
void	put_img_to_win_p(t_vars *vars, int i, int j);

void	init_ints(int *i, int *k, int *crds_index);
void	init_w(t_vars *vars, int *i, int *k, int *crds_index);
void	init_e(t_vars *vars, int *i, int *k, int *crds_index);
void	init_c(t_vars *vars, int *i, int *k, int *crds_index);

void	build_f(t_vars *vars);
void	build_w(t_vars *vars);
void	build_e(t_vars *vars);
void	build_c(t_vars *vars);
void	build_p(t_vars *vars);

int		ft_close_esc(t_vars *vars);
int		ft_close_mouse(t_vars *vars);

char	*read_map(char *file_map);

#endif