/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bsq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:23:21 by gaeokim           #+#    #+#             */
/*   Updated: 2022/06/07 19:00:30 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	make_map(int ***map, char **arr, t_map_info info)
{
	int	i;
	int	j;
	int	value[3];

	i = -1;
	while (++i < info.row)
	{
		j = -1;
		while (++j < info.col)
		{
			if (arr[i + 1][j] == info.obs)
				(*map)[i][j] = 0;
			else if (i == 0 || j == 0)
				(*map)[i][j] = 1;
			else
			{
				value[0] = (*map)[i - 1][j];
				value[1] = (*map)[i][j - 1];
				value[2] = (*map)[i - 1][j - 1];
				(*map)[i][j] = min_value(value, 3) + 1;
			}
		}
	}
}

int	max_index(int **map, t_map_info info, t_loc *loc)
{
	int	i;
	int	j;
	int	max;

	i = -1;
	max = 0;
	while (++i < info.row)
	{
		j = -1;
		while (++j < info.col)
		{
			if (max < map[i][j])
			{
				max = map[i][j];
				loc->y = i;
				loc->x = j;
			}
		}
	}
	return (max);
}

void	bsq(char ***arr, int max, t_loc loc, t_map_info info)
{
	int	i;
	int	j;

	i = loc.y - max;
	while (++i <= loc.y)
	{
		j = loc.x - max;
		while (++j <= loc.x)
			(*arr)[i + 1][j] = info.full;
	}
}

void	print_arr(char **arr, t_map_info info)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= info.row)
	{
		j = -1;
		while (++j < info.col)
			write(1, &arr[i][j], 1);
		write(1, "\n", 1);
	}
}

void	find_biggest_square(char **arr, t_map_info *info)
{
	int		**map;
	t_loc	loc;
	int		max;
	int		i;

	map = (int **)malloc(sizeof(int *) * info->row);
	if (!map)
		exit(0);
	i = -1;
	while (++i < info->row)
	{
		map[i] = (int *)malloc(sizeof(int) * info->col);
		if (!map[i])
			exit(0);
	}
	make_map(&map, arr, *info);
	max = max_index(map, *info, &loc);
	bsq(&arr, max, loc, *info);
	print_arr(arr, *info);
	i = 0;
	while (i < info->row)
		free (map[i++]);
	free (map);
}
