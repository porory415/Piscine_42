/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghhan <junghhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 16:23:09 by junghhan          #+#    #+#             */
/*   Updated: 2022/05/22 15:39:27 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	pres_x;
	int	pres_y;

	pres_y = 1;
	while (pres_y <= y && x > 0)
	{
	pres_x = 1;
		while (pres_x <= x)
		{
			if ((pres_x == 1 && pres_y == 1) || (pres_x == 1 && pres_y == y))
				ft_putchar('A');
			else if
			((pres_x == x && pres_y == 1) || (pres_x == x && pres_y == y))
				ft_putchar('C');
			else if
			((1 == pres_x) || (pres_x == x) || (pres_y == 1) || (pres_y == y))
				ft_putchar('B');
			else
				ft_putchar(' ');
		pres_x++;
		}
		ft_putchar('\n');
	pres_y++;
	}
}
