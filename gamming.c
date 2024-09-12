/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:34:09 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 14:56:52 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_manage_events(int keysym, t_game *game)
{
	int	position;

	position = keysym;
	if (keysym == W || keysym == UP)
		ft_player_moves(game, game->map->p_pos_y, game->map->p_pos_x -1, \
		position);
	if (keysym == A || keysym == LEFT)
		ft_player_moves(game, game->map->p_pos_y - 1, game->map->p_pos_x, \
		position);
	if (keysym == D || keysym == RIGHT)
		ft_player_moves(game, game->map->p_pos_y + 1, game->map->p_pos_x, \
		position);
	if (keysym == S || keysym == DOWN)
		ft_player_moves(game, game->map->p_pos_y, game->map->p_pos_x + 1, \
		position);
	if (keysym == QUIT || keysym == Q)
		ft_close_game(game);
	ft_printf(RED"movements: "RESET"%d\n", game->map->movements);
	return (0);
}

void	ft_player_moves(t_game *game, int y, int x, int position)
{
	int	prev_y;
	int	prev_x;

	prev_y = game->map->p_pos_y;
	prev_x = game->map->p_pos_x;
	if ((game->map->mapa[y][x] == 'E') && (game->map->count_c == 0))
		ft_victory(game);
	else if ((game->map->mapa[y][x] == 'C') || (game->map->mapa[y][x] == '0'))
	{
		game->map->mapa[prev_y][prev_x] = '0';
		if (game->map->mapa[y][x] == 'C')
			game->map->count_c--;
		game->map->p_pos_y = y;
		game->map->p_pos_x = x;
		game->map->mapa[y][x] = 'P';
		game->map->movements++;
		put_imgs(game, position);
	}
	else if (game->map->mapa[y][x] == 'N')
		ft_loose_game(game);
}

void	ft_victory(t_game *game)
{
	ft_printf("WIN!");
	ft_free_game(game);
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	ft_free_game(game);
	ft_printf("CLOSED\n");
	exit (EXIT_FAILURE);
}

void	ft_loose_game(t_game *game)
{
	ft_printf("YOU LOSE, TRY AGAIN\n");
	ft_free_game(game);
	exit (EXIT_FAILURE);
}
