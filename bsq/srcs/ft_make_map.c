/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:22:49 by gaeokim           #+#    #+#             */
/*   Updated: 2022/06/08 22:51:38 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	put_info(int file, t_map_info *info, char **buff)
{
	int	read_byte;
	int	offset;

	read_byte = read(file, *buff, BUFF_SIZE);
	if (read_byte < 0)
		return (0);
	info->row = ft_atoi((*buff), read_byte - 4);
	if (info->row == 0)
		return (0);
	offset = read_byte - 2;
	info->full = (*buff)[offset--];
	info->obs = (*buff)[offset--];
	info->empty = (*buff)[offset];
	return (1);
}

int	make_file_map(int file, char ***arr, t_map_info *info)
{
	char		buff[BUFF_SIZE];
	int			read_byte;
	int			offset;

	offset = -1;
	while (++offset < BUFF_SIZE)
		buff[offset] = 0;
	read_byte = read(file, buff, BUFF_SIZE);
	if (read_byte < 0)
		exit(0);
	*arr = ft_split(buff);
	if (!*arr)
		exit(0);
	info->row = ft_atoi((*arr)[0], ft_strlen((*arr)[0]) - 3);
	offset = ft_strlen((*arr)[0]) - 1;
	info->full = (*arr)[0][offset--];
	info->obs = (*arr)[0][offset--];
	info->empty = (*arr)[0][offset];
	return (valid_check(*arr, info));
}

int	make_std_map(int file, char ***arr, t_map_info *info)
{
	char		*buff;
	int			read_byte;
	int			offset;

	buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if (!buff)
		exit(0);
	if (!put_info(file, info, &buff))
		exit(0);
	(*arr) = (char **)malloc(sizeof(char *) * (info->row + 2));
	if (!(*arr))
		exit(0);
	(*arr)[0] = ft_strdup(buff);
	offset = 1;
	while (offset <= info->row)
	{
		read_byte = read(file, buff, BUFF_SIZE);
		if (read_byte < 0)
			exit(0);
		(*arr)[offset++] = ft_strdup(buff);
	}
	free(buff);
	(*arr)[offset] = 0;
	return (valid_check(*arr, info));
}

int	valid_check(char **arr, t_map_info *info)
{
	int	i;
	int	j;
	int	col;

	if (info->empty == info->obs
		|| info->obs == info->full
		|| info->full == info->empty)
		return (0);
	i = 0;
	col = 0;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
			if (arr[i][j] != info->empty && arr[i][j] != info->obs)
				return (0);
		if (i == 1)
			col = j;
		else if (col != j)
			return (0);
	}
	if (i - 1 != info->row || col == 0)
		return (0);
	info->col = col;
	return (1);
}
