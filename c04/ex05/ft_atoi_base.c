/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:06:08 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/01 16:16:45 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	g_idx;

int	is_invalid_arg_(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
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

int	ft_atoi_sign(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i] <= 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	g_idx = i;
	return (sign);
}

int	is_match_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	len;
	int				sign;
	long			result;

	len = 0;
	sign = ft_atoi_sign(str);
	result = 0;
	while (base[len] != '\0')
		len++;
	if (is_invalid_arg_(base) == 0)
		return (0);
	while (str[g_idx] != '\0')
	{
		if (is_match_base (base, str[g_idx]) != -1)
		{
			result *= len;
			result += is_match_base(base, str[g_idx]);
		}
		else
			break ;
		g_idx++;
	}
	return (result * sign);
}
