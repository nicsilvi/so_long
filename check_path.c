/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:56:54 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 14:25:39 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_path(t_game *game)
{
	int	p_pos_y;
	int	p_pos_x;
	int	collectable;

	collectable = 0;
	p_pos_y = game->map->p_pos_y;
	p_pos_x = game->map->p_pos_x;
	flood_fill(game, p_pos_y, p_pos_x, &collectable);
	if (collectable != game->map->count_c || game->map->aux_e != 1)
		return (1);
	return (0);
}

void	flood_fill(t_game *game, int y, int x, int *collectable)
{
	if (x < 0 || y < 0 || x >= game->map->len || y >= game->map->num_lines \
		|| game->map->auxmap[y][x] == '1')
		return ;
	else if (game->map->auxmap[y][x] == 'E')
	{
		game->map->aux_e += 1;
		game->map->auxmap[y][x] = '1';
		return ;
	}
	else if (game->map->auxmap[y][x] == 'C')
		(*collectable)++;
	game->map->auxmap[y][x] = '1';
	if (y + 1 < game->map->num_lines && (game->map->auxmap[y + 1][x] != 1 \
		|| game->map->auxmap[y + 1][x] != 'X'))
		flood_fill(game, y + 1, x, collectable);
	if (y - 1 >= 0 && (game->map->auxmap[y -1][x] != 1 \
		|| game->map->auxmap[y - 1][x] != 'X'))
		flood_fill(game, y - 1, x, collectable);
	if (x + 1 < game->map->len && (game->map->auxmap[y][x - 1] != 1 \
		|| game->map->auxmap[y][x - 1] != 'X'))
		flood_fill(game, y, x -1, collectable);
	if (x - 1 >= 0 && (game->map->auxmap[y][x + 1] != 1 \
		|| game->map->auxmap[y][x + 1] != 'X'))
		flood_fill(game, y, x + 1, collectable);
}
