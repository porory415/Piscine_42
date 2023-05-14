/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:37:37 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/23 11:41:21 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	shownbr(long nb)
{
	char	a;

	if (nb < 10)
	{
		a = nb + '0';
		write (1, &a, 1);
		return ;
	}
	else
		shownbr(nb / 10);
	a = (nb % 10) + '0';
	write(1, &a, 1);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	b;

	b = nb;
	if (nb < 0)
	{
		b *= -1;
		ft_putchar('-');
	}
	shownbr(b);
}
