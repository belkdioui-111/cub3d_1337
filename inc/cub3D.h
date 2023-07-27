/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:04:20 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/27 15:29:36 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

#define  height 1080
#define	width 1920
#define  height_map 250
#define	width_map 350

# define ESC 53
# define PI M_PI
# define W 13
# define A 0
# define S 1
# define D 2
# define ON_DESTROY 17
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123



/*---------- struct cast rays ---------*/
typedef struct s_cast_ray
{
	int		num_of_rays;
	float	dr;
	int		rays;
	float	ry;
	float	rx;
	float	dish;
	float	hx;
	float	hy;
	float	disv;
	float	vx;
	float	vy;
	float	final_dis;
	float	atan;
	float	ntan;
	int		dof;
	int		mx;
	int		my;
	float	xo;
	float	yo;
	float	ra;
}				t_cast_ray;
/*----- data the my_mlx_pixel_put --------*/

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_ele
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**map;
	char		*str;
}				t_ele;

typedef	struct s_game
{
	int			w;
	int			h;
	int			x;
	int			y;
	int			x_p;
	int			y_p;
	int			w_sq;
	int			h_sq;
	double		x_p_move;
	double		y_p_move;
	double		pdx;
	double		pdy;
	double		endpoint_x;
	double		endpoint_y;
	t_data		data;
	t_cast_ray	*cast_ray;
	float		rot_pl;
	int			i;
	int			j;
}			t_game;

/*--------- strcut the mlx -----------*/

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			x;
	int			y;
	int			x_map;
	int			y_map;
	double		x_p_move;
	double		y_p_move;
	int			x_p;
	int			y_p;
	int			x_p_map;
	int			y_p_map;
	float		rot_pl;
	double		pdx;
	double		pdy;
	int			num_of_player;
	double		endpoint_x;
	double		endpoint_y;
	t_data		data;
	t_data		data2;
	t_ele		*ele;
	t_cast_ray	*cast_ray;
	
	int		w_sq;
	int		h_sq;
	int		w_sq_map;
	int		h_sq_map;
}				t_mlx;

typedef	struct s_global
{
	t_mlx		*mlx_cub;
	t_game		*game;
	t_game		*mini_game;
	t_ele		*ele;
	float		rot_pl;
	int			num_of_player;
}				t_gloabl;

typedef struct s_vars
{
	int			i;
	int			j;
	int			is_ele;
	int			check;
}				t_vars;

// utils
int				search_and_ret_place(char *av);
int				cal_number_of_lines_map(char **cnt_file);
void			free_db(char **arr);
int				len_of_longest_line(char **pre_map);
//
int				space_is_protected(char **map, int x, int y);
int				if_bet_first_and_last(char **map, int i, int *j, t_gloabl *glob);
int				check_rgb(char *rgb);
int				check_img(char *textures);
int				is_element(char *line, int *ele);
char			*ret_element(char *line, int num_of_ele);
char			*is_element_and_saveit(char **cnt_file, int which_ele,
					char ***save_map);
char			**ver_and_ret_map(int ac, char **av);
int				check_the_map(char **cnt_file, t_ele *ele, t_gloabl *glob);
/*----- mlx utils -------*/
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				close_window(t_mlx *mlx_cub);
int				key_hock(int keycode, t_gloabl *glob);

/*----- drawing map -------*/
t_ele			*get_map(int ac, char **av, t_gloabl *glob);
void			init(t_mlx *mlx_cub);
void			drawing_map(char **map, t_mlx *mlx_cub, t_data *data);
void			free_ele(t_ele *ele);
void			cast_rays(t_game *game, char **map, int check);
int				draw_line(t_game *game, int beginX, int beginY, int check);

/*-------- cast rays ------------*/
t_cast_ray		*init_strcut_cast_ray(t_game *game, int check);
float			calc_dist(float px, float py, float dx, float dy);
void			set_the_min_pos(t_game *game);

/*--------- key hooks ------------*/
void			key_w(t_game *game, char **map, int tmp_xp, int tmp_yp);
void			key_s(t_game *game, char **map, int tmp_xp, int tmp_yp);
void			key_a(t_game *game, char **map, int tmp_xp, int tmp_yp);
void			key_d(t_game *game, char **map, int tmp_xp, int tmp_yp);


/*--------- last update ------------*/
t_gloabl	*init_global(t_gloabl *glob, int ac, char **av);
void		draw_game(t_game *game, char **map, int check);
t_ele		*get_map(int ac, char **av, t_gloabl *glob);
void		finish(t_gloabl *glob);
void		check_size(t_gloabl *glob, t_game *game);
void		draw(t_gloabl *glob);

#endif