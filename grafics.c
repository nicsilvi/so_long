/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:56:08 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 14:48:49 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_windows(t_game *game)
{
	int	y_height;
	int	x_width;

	x_width = ((game->map->num_lines) * IMG_SIZE);
	y_height = ((game->map->len) * IMG_SIZE);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error_msg("error init windows", game);
	game->windws = mlx_new_window(game->mlx, x_width, y_height, "so_long");
	if (!game->windws)
		ft_error_msg("error open windows", game);
	init_images(game);
}

void	init_images(t_game *game)
{
	int	i;
	int	j;

	game->img->ground = mlx_xpm_file_to_image(game->mlx, GROUND, &i, &j);
	game->img->player_up = mlx_xpm_file_to_image(game->mlx, PLAYER_UP, &i, &j);
	game->img->player_down = mlx_xpm_file_to_image(game->mlx, PLAYER_DOWN, \
	&i, &j);
	game->img->player_right = mlx_xpm_file_to_image(game->mlx, PLAYER_RIGHT, \
	&i, &j);
	game->img->player_left = mlx_xpm_file_to_image(game->mlx, PLAYER_LEFT, \
	&i, &j);
	game->img->enemy = mlx_xpm_file_to_image(game->mlx, ENEMY, \
	&game->img->width, &game->img->height);
	game->img->coin1 = mlx_xpm_file_to_image(game->mlx, COIN1, \
	&game->img->width, &game->img->height);
	game->img->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->img->width, \
	&game->img->height);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &game->img->width, \
	&game->img->height);
	if ((!game->img->ground) || (!game->img->player_up) || (!game->img->coin1) \
	|| (!game->img->wall) || (!game->img->exit))
		ft_error_msg("cannot init image", game);
	put_imgs(game, DOWN);
}

int	put_imgs(t_game *game, int position)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->mapa[i] != NULL)
	{
		j = 0;
		while (game->map->mapa[i][j] != '\0')
		{
			put_each_img(game, i, j, position);
			j++;
		}
		i++;
		put_movements(game);
	}
	return (0);
}

void	put_each_img(t_game *game, int i, int j, int position)
{
	if (game->map->mapa[i][j] == 'P')
		player_images(game, i, j, position);
	else if (game->map->mapa[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->windws, game->img->exit, \
		i * IMG_SIZE, j * IMG_SIZE);
	else if (game->map->mapa[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->windws, game->img->coin1, \
		i * IMG_SIZE, j * IMG_SIZE);
	else if (game->map->mapa[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->windws, game->img->wall, \
		i * IMG_SIZE, j * IMG_SIZE);
	else if (game->map->mapa[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->windws, game->img->ground, \
		i * IMG_SIZE, j * IMG_SIZE);
	else if (game->map->mapa[i][j] == 'N')
		mlx_put_image_to_window(game->mlx, game->windws, game->img->enemy, \
		i * IMG_SIZE, j * IMG_SIZE);
	else
		return ;
}

void	player_images(t_game *game, int i, int j, int position)
{
	if (position == UP || position == W)
		mlx_put_image_to_window(game->mlx, game->windws, \
		game->img->player_up, i * IMG_SIZE, j * IMG_SIZE);
	else if (position == LEFT || position == A)
		mlx_put_image_to_window(game->mlx, game->windws, \
		game->img->player_left, i * IMG_SIZE, j * IMG_SIZE);
	else if (position == RIGHT || position == D)
		mlx_put_image_to_window(game->mlx, game->windws, \
		game->img->player_right, i * IMG_SIZE, j * IMG_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->windws, \
		game->img->player_down, i * IMG_SIZE, j * IMG_SIZE);
}
