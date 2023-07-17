/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-kdio <bel-kdio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:18:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/07/17 12:05:04 by bel-kdio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	change_position_the_player(char **map, int keycode)
{
	int		i;
	int		j;
	char	player;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (keycode == ARROW_UP)
				{
					player = map[i][j];
					map[i][j] = '0';
					if (map[i - 1] && map[i - 1][j] != '\0' && map[i - 1][j] != '1')
						map[i - 1][j] = player;
				}
				else if (keycode == ARROW_DOWN)
				{
					player = map[i][j];
					map[i][j] = '0';
					if (map[i + 1] && map[i + 1][j] != '\0' && map[i + 1][j] != '1')
						map[i + 1][j] = player;
				}
				else if (keycode == ARROW_RIGHT)
				{
					player = map[i][j];
					map[i][j] = '0';
					if (map[i][j + 1] != '\n' && map[i][j + 1] != '\0' && map[i][j + 1] != '1')
						map[i][j + 1] = player;
					else
						map[i][j] = player;
				}
				else if (keycode == ARROW_LEFT)
				{
					player = map[i][j];
					map[i][j] = '0';
					if (map[i][j - 1] != '\n' && map[i][j - 1] != '\0' && map[i][j - 1] != '1')
						map[i][j - 1] = player;
					else
						map[i][j] = player;
				}
			}
			j++;
		}
		i++;
	}
}

void	arrows_keys(int keycode, t_mlx *mlx_cub)
{
	if (keycode == ARROW_UP)
	{
		if (mlx_cub->y_up != '1')
			mlx_cub->y_player -= 20;
	}
	else if (keycode == ARROW_DOWN)
	{
		if (mlx_cub->y_down != '1')
			mlx_cub->y_player += 20;
	}
	else if (keycode == ARROW_RIGHT)
	{
		if (mlx_cub->x_right != '1')
			mlx_cub->x_player += 20;
	}
	else if (keycode == ARROW_LEFT)
	{
		if (mlx_cub->x_left != '1')
			mlx_cub->x_player -= 20;
	}
	// change_position_the_player(mlx_cub->map, keycode);
	mlx_clear_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
	drawing_map(mlx_cub->map, mlx_cub);
	mlx_put_image_to_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win, \
			mlx_cub->data.img, 0, 0);
}
int	key_hock(int keycode, t_mlx *mlx_cub)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx_cub->mlx_ptr, mlx_cub->mlx_win);
		free(mlx_cub->mlx_ptr);
		exit(0);
	}
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN || \
		keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		arrows_keys(keycode, mlx_cub);
	return (0);
}