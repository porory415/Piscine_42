/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:24:59 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/22 12:42:25 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	show_nbr(char arr[], int n)
{
	write (1, arr, n);
	if (arr[0] == 10 - n + '0' && arr[n - 1] == '9')
		return ;
	write (1, ", ", 2);
}

void	ft_print_combn(int n)
{
	char	arr1[10];
	int		i;

	arr1[0] = '0';
	i = 1;
	while (i < n)
	{
		arr1[i] = arr1[i - 1] + 1;
		i++;
	}
	show_nbr(arr1, n);
	while (arr1[0] != 10 - n + '0' || arr1[n - 1] != '9')
	{
		i = n - 1;
		while (arr1[i] == (10 - n + i) + '0')
			i--;
		arr1[i]++;
		i++;
		while (i < n)
		{
			arr1[i] = arr1[i - 1] + 1;
			i++;
		}
		show_nbr(arr1, n);
	}
}
