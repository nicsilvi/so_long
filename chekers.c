/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:48:35 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 15:20:23 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_filename(char *file, t_game *game)
{
	char	*result;

	if (!file)
		ft_error_msg("invalid file", game);
	result = ft_strnstr(file, ".ber", ft_strlen(file));
	if (result == NULL)
		ft_error_msg("error extension", game);
	if (ft_strncmp(result, ".ber", 3) != 0)
		ft_error_msg("error extension", game);
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		ft_error_msg("error al crear el map", game);
		exit (-1);
	}
	game->map->filename = file;
	game->map->mapa = NULL;
}

void	check_valid_map(t_game *game)
{
	if (game->map->len > 29)
		ft_error_msg("mapa demasiado grande", game);
	check_rectangle(game->map, game);
	check_count_elements(game->map, game);
	check_walls_h(0, game->map, game);
	check_walls_h(game->map->num_lines - 1, game->map, game);
	check_walls_v(0, game->map, game);
	check_walls_v(game->map->len - 1, game->map, game);
}

void	check_rectangle(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map->mapa[i] != NULL)
	{
		j = 0;
		while (map->mapa[i][j] != '\0')
			j++;
		if (j != map->len)
			ft_error_msg("no same extension lines", game);
		i++;
	}
	if (map->num_lines == j)
		ft_error_msg("map not allowed", game);
}

void	check_count_elements(t_map *map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map->mapa[i] != NULL)
	{
		j = 0;
		while (map->mapa[i][j] != '\0')
		{
			if (!ft_checker_elements(map, map->mapa[i][j], i, j))
				ft_error_msg("error elements", game);
			j++;
		}
		i++;
	}
	if ((map->count_p != 1) || (map->count_e != 1) || (!map->count_c))
		ft_error_msg("error elements", game);
}

int	ft_checker_elements(t_map *map, char c, int i, int j)
{
	if (c == 'P')
	{
		map->count_p++;
		map->p_pos_y = i;
		map->p_pos_x = j;
		return (1);
	}
	else if (c == 'E')
	{
		map->count_e++;
		return (1);
	}
	else if (c == 'C')
	{
		map->count_c++;
		return (1);
	}
	else if ((c == '0') || (c == '1') || (c == 'N'))
		return (1);
	else
		return (0);
}
