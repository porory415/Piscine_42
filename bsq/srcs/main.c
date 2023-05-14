/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:21:29 by gaeokim           #+#    #+#             */
/*   Updated: 2022/06/08 22:51:45 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_map_init(char **arr, t_map_info *info, int *file)
{
	int	i;

	i = -1;
	while (++i < info->row)
		free (arr[i]);
	free (arr);
	info->col = 0;
	info->row = 0;
	info->empty = '\0';
	info->full = '\0';
	info->obs = '\0';
	if (close(*file) != 0)
		exit(0);
	*file = -1;
}

void	ft_std_input(void)
{
	char		**arr;
	int			file;
	t_map_info	info;

	file = 0;
	if (make_std_map(file, &arr, &info))
		find_biggest_square(arr, &info);
	else
		ft_putstr(2, MSG_MAP_ERR);
	ft_map_init(arr, &info, &file);
}

void	ft_file_input(int argc, char **argv)
{
	char		**arr;
	int			file;
	int			i;
	t_map_info	info;

	i = 0;
	while (++i < argc)
	{
		file = open(argv[i], O_RDONLY, 0755);
		if (file != -1)
		{
			if (make_file_map(file, &arr, &info))
				find_biggest_square(arr, &info);
			else
				ft_putstr(2, MSG_MAP_ERR);
		}
		else
			ft_putstr(2, MSG_MAP_ERR);
		ft_map_init(arr, &info, &file);
		if (i < argc - 1)
			write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_std_input();
	else
		ft_file_input(argc, argv);
	return (0);
}
