/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:04:30 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/06 00:32:41 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr(int nb)
{
	char		nb_table[15];
	int			i;
	long		n;

	i = 0;
	n = (long)nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	while (n >= 0)
	{
		nb_table[i++] = '0' + (n % 10);
		n /= 10;
		if (n == 0)
			break ;
	}
	i -= 1;
	while (i >= 0)
		write(1, &nb_table[i--], 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, str_len(par[i].str));
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, str_len(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}
