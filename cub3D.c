/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:45 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/17 12:37:11 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

t_ele	*get_map(int ac, char **av)
{
	char	**cnt_file;
	t_ele	*ele;

	cnt_file = ver_and_ret_map(ac, av);
	if (!cnt_file)
	{
		ft_putstr_fd("error in the name\n", 2);
		exit(1);
	}
	ele = malloc(sizeof(t_ele));
	if (!check_the_map(cnt_file, ele))
	{
		ft_putstr_fd("error in the map\n", 2);
		exit(1);
	}
	return (ele);
	system("leaks cub3D");
}

void	draw_map(t_mlx *mlx_cub, t_ele *ele)
{
	mlx_cub = malloc(sizeof(t_mlx));
	if (!mlx_cub)
		exit (1);
	init(mlx_cub, ele->map);
	mlx_cub->map = ele->map;
	drawing_map(ele->map, mlx_cub);
	mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win,
		mlx_cub->data.img, 0, 0);
	mlx_hook(mlx_cub->mlx_win, 2, 0, key_hock, mlx_cub);
	mlx_hook(mlx_cub->mlx_win, ON_DESTROY, 0, close_window, mlx_cub);
	mlx_loop(mlx_cub->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_ele	*ele;
	t_mlx	*mlx_cub;

	mlx_cub = NULL;
	ele = get_map(ac, av);
	exit(1);
	if (ele->map)
		draw_map(mlx_cub, ele);
	return (1);
}
