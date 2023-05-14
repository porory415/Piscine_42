/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:44:33 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/09 21:48:01 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (result * sign);
}

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

void	ft_putnbr(int nb)
{
	long	b;

	b = nb;
	if (nb < 0)
	{
		b *= -1;
		write (1, "-", 1);
	}
	shownbr(b);
}
