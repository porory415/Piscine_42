/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donkwak <donkwak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:44:01 by donkwak           #+#    #+#             */
/*   Updated: 2022/05/21 19:48:55 by donkwak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*      RUSH00      */

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
			if ((pres_x == 1 && pres_y == 1) || (pres_x == x && pres_y == 1)
				|| (pres_x == 1 && pres_y == y) || (pres_x == x && pres_y == y))
				ft_putchar('o');
			else if (((1 < pres_x) && (pres_x < x))
				&& (pres_y == 1 || pres_y == y))
				ft_putchar('-');
			else if (((1 < pres_y) && (pres_y < y))
				&& (pres_x == 1 || pres_x == x))
				ft_putchar('|');
			else
				ft_putchar(' ');
			pres_x++;
		}
		ft_putchar('\n');
		pres_y++;
	}
}
