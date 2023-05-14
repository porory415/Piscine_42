/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:26:56 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/22 12:41:41 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	show_digits(int a, int b)
{
	char	arr[2];

	arr[0] = a / 10 + '0';
	arr[1] = a % 10 + '0';
	write (1, arr, 2);
	write(1, " ", 1);
	arr[0] = b / 10 + '0';
	arr[1] = b % 10 + '0';
	write (1, arr, 2);
	if (a == 98 && b == 99)
		return ;
	write (1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			show_digits(a, b);
			b++;
		}
		a++;
	}
}
