/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:03:09 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/29 16:27:14 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_arr(int	**arr, int size)
{
	int i;

	i = 0;
	while (i <size)
	{
		free(arr[i++]);
	}
	free(arr);
}

int	**allocate_memory(int size)
{
	int	i;
	int	j;
	int	**arr;

	i = 0;
	arr = (int **)malloc(sizeof(int *) * size);
	while (i < size)
	{
		arr[i] = (int *)malloc(sizeof(int) * size);
		j = 0;
		while (j  < size)
			arr[i][j++] = 0;
		i++;
	}
	return (arr);
}