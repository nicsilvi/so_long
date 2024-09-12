/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:44:23 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 15:15:40 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = NULL;
	game.img = NULL;
	game.mlx = NULL;
	if (argc != 2)
		ft_error_msg("error argumentos", &game);
	check_filename(argv[1], &game);
	create_map(&game);
	init_map_var(&game);
	check_valid_map(&game);
	if (verif_path(&game))
		ft_error_msg("error en el path\n", &game);
	init_windows(&game);
	mlx_hook(game.windws, KeyPress, KeyPressMask, ft_manage_events, &game);
	mlx_hook(game.windws, DestroyNotify, ButtonPressMask, ft_close_game, &game);
	mlx_hook(game.windws, Expose, ExposureMask, put_imgs, &game);
	mlx_loop(game.mlx);
	ft_free_game(&game);
}

void	init_map_var(t_game *game)
{
	game->map->len = ft_strlen(game->map->mapa[0]);
	game->map->count_p = 0;
	game->map->aux_e = 0;
	game->map->count_c = 0;
	game->map->count_e = 0;
	game->map->movements = 0;
	game->map->num_lines = get_heigh(game->map->mapa);
	game->windws = NULL;
	game->img = malloc(sizeof(t_img));
	if (!game->img)
		ft_error_msg("error al iniciar imagenes", game);
	game->img->height = IMG_SIZE;
	game->img->width = IMG_SIZE;
	game->img->exit = NULL;
}

void	create_map(t_game *game)
{
	int		fd;
	char	*line;
	char	*joined_lines;

	line = "";
	joined_lines = ft_strdup("");
	fd = open(game->map->filename, O_RDONLY);
	if (fd < 0)
	{
		free(joined_lines);
		ft_error_msg("error al abrir el archivo", game);
	}
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		joined_lines = ft_strjoin(joined_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	game->map->mapa = ft_split(joined_lines, '\n');
	game->map->auxmap = ft_split(joined_lines, '\n');
	free(joined_lines);
}
