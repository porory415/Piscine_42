/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:23:48 by gaeokim           #+#    #+#             */
/*   Updated: 2022/06/07 19:02:17 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define MSG_MAP_ERR "map error\n"
# define BUFF_SIZE 3000000

typedef struct s_map
{
	int		row;
	int		col;
	char	empty;
	char	obs;
	char	full;
}	t_map_info;

typedef struct s_loc
{
	int	x;
	int	y;
}	t_loc;

int		make_file_map(int file, char ***arr, t_map_info *info);
int		make_std_map(int file, char ***arr, t_map_info *info);
int		valid_check(char **arr, t_map_info *info);

int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	**ft_split(char *str);
void	ft_putstr(int file, char *str);
int		ft_atoi(char *str, int size);

int		min_value(int *arr, int size);
void	find_biggest_square(char **arr, t_map_info *info);

#endif