/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:22:45 by bel-kdio          #+#    #+#             */
/*   Updated: 2023/07/27 15:30:55 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

void	draw(t_gloabl *glob)
{
	draw_game(glob->game, glob->ele->map, 0);
	mlx_put_image_to_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win,\
		glob->game->data.img, 0, 0);
}

void	finish(t_gloabl *glob)
{
	check_size(glob, glob->mini_game);
	draw_game(glob->game, glob->ele->map, 0);
	mlx_put_image_to_window(glob->mlx_cub->mlx_ptr, glob->mlx_cub->mlx_win,\
		glob->game->data.img, 0, 0);
	mlx_hook(glob->mlx_cub->mlx_win, 2, 0, key_hock, glob);
	mlx_hook(glob->mlx_cub->mlx_win, ON_DESTROY, 0, close_window, glob);
	mlx_loop(glob->mlx_cub->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_gloabl	*glob;

	glob = malloc(sizeof(t_gloabl));
	if (!glob)
		exit(1);
	glob = init_global(glob, ac, av);
	finish(glob);
	return (1);
}
