/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:55:15 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/23 18:00:46 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar1(char arr[3])
{
	write (1, arr, 3);
}

void	ft_print_comb(void)
{
	char	a[3];

	a[0] = '0';
	while (a[0] <= '7')
	{
		a[1] = a[0] + 1;
		while (a[1] <= '8')
		{
			a[2] = a[1] + 1;
			while (a[2] <= '9')
			{
				ft_putchar1(a);
				if (a[0] != '7' || a[1] != '8' || a[2] != '9')
					write (1, ", ", 2);
				a[2] += 1;
			}
			a[1] += 1;
		}
		a[0] += 1;
	}
}
