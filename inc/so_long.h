/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:00:55 by beboccas          #+#    #+#             */
/*   Updated: 2024/09/27 15:35:23 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/headers/ft_printf.h"
# include "../libs/gnl/get_next_line.h"
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifdef __APPLE__
#  include "../libs/minilibx_opengl/mlx.h"
# endif

# ifndef __APPLE__
#  include "../libs/minilibx-linux/mlx.h"
#  include "../libs/minilibx-linux/mlx_int.h"
# endif

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_path
{
	void			*placeholder;
	void			*background;
	void			*wall;
	void			**player;
	void			*collectible;
	void			*enemy;
	void			*exit;
}					t_path;

typedef struct s_map
{
	int				width;
	int				height;
	char			**data;
	int				collected;
	int				coins;
	bool			exit;
}					t_map;

typedef struct s_coins
{
	int			*x;
	int			*y;
}				t_coins;

typedef struct s_player
{
	int				x;
	int				y;
	int				moves;
	int				frame;
}					t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	int				x;
	int				y;
}					t_game;

typedef struct s_data
{
	char			*name;
	t_game			*game;
	t_map			*map;
	t_player		*player;
	t_path			*path;
	t_coins			*coins;
}					t_data;

void	error(t_data *data);
void	merror(t_data *data, char *message);
void	clean_exit(t_data *data);
int		key_hook(int keycode, t_data *data);
int		valid_args(int ac, char **av);
int		map_open(t_data *data, char *map);
int		map_size(int fd, t_data *data);
char	**map_loader(int buffer, t_data *data);
int		draw_map(t_data *data);
int		get_coins(t_data *data);
int		get_exit_pos(t_data *data);
int		get_coins_pos(t_data *data);
void	init(t_data *data);
int		init_game(t_data *data);
int		init_map(t_data *data);
int		init_player(t_data *data);
int		init_assets(t_data *data);
int		init_coins(t_data *data);
int		get_player_pos(char **map, char c);
void	moves_handler(t_data *data, char direction);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	update_position(t_data *data, int dy, int dx, int frame);
void	collect_coin(t_data *data, int dy, int dx, int frame);
void	check_exit(t_data *data, int dy, int dx, int frame);
int		verify_map(t_data *data);
char	**copy_map(t_data *data);
void	free_temp_map(char **map);
void	free_path(t_data *data);
void	free_game(t_game *game);
void	free_map(t_map *map);
void	free_coins(t_coins *coins);
int		free_structs(t_data *data);
void	update_frame(t_data *data, int frame);
int		valid_map(t_data *data);
char	*safe_itoa(t_data *data, int n);

#endif // SO_LONG_H