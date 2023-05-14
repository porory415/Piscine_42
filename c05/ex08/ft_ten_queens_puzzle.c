/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 19:27:40 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/02 19:51:06 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	g_count;

int	is_valid(char *arr, int col)
{
	int	i;

	i = -1;
	while (++i < col)
	{
		if (arr[i] == arr[col])
			return (0);
		else if (col - i == arr[col] - arr[i])
			return (0);
		else if (col - i == arr[i] - arr[col])
			return (0);
	}
	return (1);
}

void	find_spot(char *arr, int col)
{
	int	i;

	if (col == 10)
	{
		write (1, arr, 10);
		write (1, "\n", 1);
		g_count++;
	}
	else
	{
		i = -1;
		while (++i < 10)
		{
			arr[col] = i + '0';
			if (is_valid(arr, col))
				find_spot(arr, col + 1);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	arr[10];

	g_count = 0;
	find_spot(arr, 0);
	return (g_count);
}
