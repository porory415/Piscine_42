/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:06:02 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/31 23:55:19 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_(char a)
{
	write(1, &a, 1);
}

void	printnbr(long nb)
{
	char	a;

	if (nb < 10)
	{
		a = nb + '0';
		ft_putchar_(a);
		return ;
	}
	else
		printnbr(nb / 10);
	a = (nb % 10) + '0';
	ft_putchar_(a);
}

void	ft_putnbr(int nb)
{
	long	b;

	b = nb;
	if (nb < 0)
	{
		b *= -1;
		ft_putchar_('-');
	}
	printnbr(b);
}
