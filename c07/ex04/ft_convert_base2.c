/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 03:30:14 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/07 19:23:59 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_inbase(char nbr, char *base_from, int base_len)
{
	int	k;

	k = 0;
	while (k < base_len)
	{
		if (nbr == base_from[k])
			return (k);
		k++;
	}
	return (-1);
}

int	ft_atoi_base(char *nbr, char *base_from, int base_len)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((9 <= nbr[i] && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nbr[i] != '\0')
	{
		if (ft_inbase(nbr[i], base_from, base_len) == -1)
			break ;
		res = res * base_len + ft_inbase(nbr[i], base_from, base_len);
		i++;
	}
	return (res * sign);
}

int	ft_len(long nbr, int base_len)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

char	*ft_putnbr(long nbr, char *base_to, int len, char *str)
{
	int	sign;
	int	base_len;

	if (nbr < 0)
	{
		nbr *= -1;
		sign = -1;
	}
	base_len = 0;
	while (base_to[base_len] != '\0')
		base_len++;
	str[len + 1] = '\0';
	while (nbr > 0)
	{
		str[len] = base_to[nbr % base_len];
		nbr /= base_len;
		len--;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_base(int nbr, char *base_to, int base_len)
{
	int		len;
	char	*str;

	if (nbr == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = base_to[0];
		str[1] = '\0';
		return (str);
	}
	len = ft_len((long)nbr, base_len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	return (ft_putnbr((long)nbr, base_to, len - 1, str));
}
