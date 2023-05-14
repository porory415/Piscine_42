/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:02:51 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/21 19:12:41 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	pres_x;
	int	pres_y;

	pres_y = 0;
	while (++pres_y <= y && x > 0)
	{
		pres_x = 0;
		while (++pres_x <= x)
		{
			if ((pres_x == 1 && pres_y == 1) || (pres_x == x && pres_y == y))
				ft_putchar('A');
			else if ((pres_x == x && pres_y == 1)
				|| (pres_x == 1 && pres_y == y))
				ft_putchar('C');
			else if (((1 < pres_x) && (pres_x < x))
				&& (pres_y == 1 || pres_y == y))
				ft_putchar('B');
			else if (((1 < pres_y) && (pres_y < y))
				&& (pres_x == 1 || pres_x == x))
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
