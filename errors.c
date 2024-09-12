/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:53:17 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 15:03:05 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_msg(char *msg, t_game *game)
{
	ft_printf(RED"Error\n"GREY"%s\n"RESET, msg);
	if (game->map)
	{
		if (game->map->mapa)
		{
			ft_free_map(game->map->mapa);
			ft_free_map(game->map->auxmap);
		}
		if (game->img)
		{
			if (!game->img->exit)
				free(game->img);
			else
				ft_destroy_img(game);
		}
		if (game->mlx)
			free(game->mlx);
		free(game->map);
	}
	exit (-1);
}

void	ft_free_game(t_game *game)
{
	ft_destroy_img(game);
	ft_free_map(game->map->mapa);
	ft_free_map(game->map->auxmap);
	mlx_destroy_window(game->mlx, game->windws);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game->map);
}

void	ft_destroy_img(t_game *game)
{
	if (game->img->ground)
		mlx_destroy_image(game->mlx, game->img->ground);
	if (game->img->player_down)
		mlx_destroy_image(game->mlx, game->img->player_down);
	if (game->img->player_up)
		mlx_destroy_image(game->mlx, game->img->player_up);
	if (game->img->player_left)
		mlx_destroy_image(game->mlx, game->img->player_left);
	if (game->img->enemy)
		mlx_destroy_image(game->mlx, game->img->enemy);
	mlx_destroy_image(game->mlx, game->img->player_right);
	mlx_destroy_image(game->mlx, game->img->coin1);
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_image(game->mlx, game->img->exit);
	free(game->img);
}

void	ft_free_map(char **mapa)
{
	int	i;

	i = 0;
	if (!mapa)
		return ;
	while (mapa[i])
		free(mapa[i++]);
	free(mapa);
}
