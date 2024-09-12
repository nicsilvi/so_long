/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:55:52 by smercado          #+#    #+#             */
/*   Updated: 2024/09/12 14:47:06 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include "src/libft/libft.h"
# include "src/mlx/mlx.h"

# define IMG_SIZE 64

//colours:
# define RED	"\033[1;31m"
# define GREY	"\033[0;90m"
# define RESET	"\033[0m"

//keysym
# define W 119
# define UP 65362
# define DOWN 65364
# define S 115
# define A 97 
# define LEFT 65361
# define D 100
# define RIGHT 65363
# define Q 113
# define QUIT 65307

//imgs
# define GROUND "imgs/ground.xpm"
# define PLAYER_DOWN "imgs/cat_down.xpm"
# define PLAYER_UP "imgs/cat_up.xpm"
# define PLAYER_LEFT "imgs/cat_left.xpm"
# define PLAYER_RIGHT "imgs/cat_right.xpm"
# define WALL "imgs/wall.xpm"
# define EXIT "imgs/exit.xpm"
# define COIN1 "imgs/coin1.xpm"
# define ENEMY "imgs/enemy.xpm"
# define MOVEMENTS "img/movements.xpm"

typedef struct s_img
{
	int		height;
	int		width;
	void	*ground;
	void	*player_up;
	void	*player_down;
	void	*player_right;
	void	*player_left;
	void	*coin1;
	void	*wall;
	void	*enemy;
	void	*exit;
}			t_img;

//map info, para checkers:
typedef struct s_map
{
	char	**mapa;
	char	**auxmap;
	char	*filename;
	int		len;
	int		num_lines;
	int		movements;
	int		p_pos_y;
	int		p_pos_x;
	int		count_p;
	int		count_e;
	int		aux_e;
	int		count_c;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*windws;
	t_map	*map;
	t_img	*img;
}		t_game;

int		main(int argc, char **argv);
void	init_map_var(t_game *game);
int		get_heigh(char **mapa);
void	check_filename(char *file, t_game *game);
void	create_map(t_game *game);
void	check_valid_map(t_game *game);
void	check_rectangle(t_map *map, t_game *game);
void	check_count_elements(t_map *map, t_game *game);
int		ft_checker_elements(t_map *map, char c, int i, int j);
void	check_walls_h(int row, t_map *map, t_game *game);
void	check_walls_v(int col, t_map *map, t_game *game);
int		verif_path(t_game *game);
void	flood_fill(t_game *game, int x, int y, int *collectable);
void	put_movements(t_game *game);

//errors and frees
void	ft_error_msg(char *msg, t_game *game);
void	ft_free_game(t_game *game);
void	ft_destroy_img(t_game *game);
void	ft_free_map(char **mapa);
void	ft_loose_game(t_game *game);

//init mlx
void	init_windows(t_game *game);
void	init_images(t_game *game);
int		put_imgs(t_game *game, int position);
void	put_each_img(t_game *game, int i, int j, int position);
void	player_images(t_game *game, int i, int j, int position);

//gamming and events
int		ft_manage_events(int keysym, t_game *game);
void	ft_player_moves(t_game *game, int y, int x, int position);
void	ft_victory(t_game *game);
int		ft_close_game(t_game *game);

#endif
