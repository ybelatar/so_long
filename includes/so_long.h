/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:40:06 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/19 16:18:23 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../srcs/ft_printf/ft_printf.h"
# include "../srcs/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_DEF "Error\n"
# define ERR_UKNWN "Error\nUnvalid character in map\n"
# define ERR_EXTENSION "Error\nWrong file extension : file must be .ber\n"
# define ERR_OPEN "Error\nCannot open the map file\n"
# define ERR_READ "Error\nCannot read the map file\n"
# define ERR_RECTANGLE "Error\nMap must be a rectangle\n"
# define ERR_CLOSED "Error\nMap must be closed\n"
# define ERR_COUNT "Error\nToo many or too few of interactive game components\n"
# define ERR_WINNABLE "Error\nMap is not winnable\n"
# define ERR_MLX "Error\nCannot load the minilibX\n"
# define ERR_SCREEN "Error\nMap is too big for screen size\n"
# define ERR_MALLOC "Error\nMalloc failed\n"
# define EXIT "Esc pressed\n"

/*2-dimension vector that signals the player's position*/

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

/*Simple structure gathering the counts I'll perform on the map*/

typedef struct s_map_cpt
{
	int			player;
	int			exit;
	int			collectible;
	int			lines;
	int			columns;
}				t_map_cpt;

/*Structure containing all the sprites ready for display*/
typedef struct s_sprite
{
	void		*player;
	void		*exit;
	void		*collectible;
	void		*floor;
	void		*wall;
}				t_sprite;

/*This is the main structure which joins all
the essentials components of the working game*/

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_sprite	sprite;
	char		**map;
	t_pos		position;
	t_map_cpt	counter;
	int			steps;
	int			fd;
}				t_game;

/* Parsing */

void			init_map(char *path, t_game *game);
void			check_winnable(t_game *game);
void			check_rectangle(t_game *game);
int				check_extension(char *path);
void			check_count(t_game *game);
void			check_closed(t_game *game);

/* Graphic interface */

void			init_gui(t_game *game);
void			import_sprites(t_game *game);
int				check_sprites(t_game *game);
void			put_images(t_game *game);
int				controls(int key, t_game *game);

/* Error and Exit */

void			exit_error(char *str, int fmap, int fmlx, t_game *game);
void			exit_win(t_game *game);
int				exit_click(t_game *game);
void			exit_size(t_game *game);
void			free_map(char **map);

/* Utils */

char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
int				plen(char **map);
char			**join_tab(char **map, char *str);
int				ft_strlen(const char *str);
void			ft_putstr(char *str);
char			**ft_copy(char **map, t_game *game);

#endif