/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:57 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 14:33:02 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_heigh(char **mapa)
{
	int	i;

	i = 0;
	if (!mapa)
		return (0);
	while (mapa[i])
	{
		if (!mapa[i])
			return (i - 1);
		i++;
	}
	return (i);
}

void	put_movements(t_game *game)
{
	char	*num;
	char	*str;

	num = ft_itoa(game->map->movements);
	str = ft_strjoin(ft_strdup("movements: "), num);
	free(num);
	mlx_string_put(game->mlx, game->windws, IMG_SIZE, IMG_SIZE, 0XFF0000, str);
	free(str);
}

void	check_walls_h(int row, t_map *map, t_game *game)
{
	int	j;

	j = 0;
	while (map->mapa[row][j] != '\0')
	{
		if (map->mapa[row][j] != '1')
			ft_error_msg("error paredes", game);
		j++;
	}
}

void	check_walls_v(int col, t_map *map, t_game *game)
{
	int	i;

	i = 0;
	while (i < map->num_lines)
	{
		if (map->mapa[i][col] != '1')
			ft_error_msg("error paredes", game);
		i++;
	}
}
