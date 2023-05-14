/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 22:38:32 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/31 23:50:30 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_invalid_arg(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = -1;
	while (base[++i] != '\0')
	{
		j = -1;
		while (base[++j] != '\0')
			if (base[i] == base[j] && i != j)
				return (0);
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_convert_to_base(long long nbr, char *base, int size)
{
	if (nbr < 0)
	{
		write (1, "-", 1);
		nbr *= -1;
	}
	if (nbr < size)
		write(1, &base[nbr], 1);
	else
	{
		ft_convert_to_base(nbr / size, base, size);
		ft_convert_to_base(nbr % size, base, size);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = 0;
	if (is_invalid_arg(base) == 1)
	{
		while (base[i] != '\0')
			i++;
		ft_convert_to_base((long long)nbr, base, i);
	}
}
