/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:21:58 by gaeokim           #+#    #+#             */
/*   Updated: 2022/06/07 19:04:32 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	min_value(int *arr, int size)
{
	int	i;
	int	min;

	i = 0;
	min = arr[0];
	while (++i < size)
	{
		if (min > arr[i])
			min = arr[i];
	}
	return (min);
}

void	ft_putstr(int file, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		i++;
	write(file, str, i);
}

int	ft_atoi(char *str, int size)
{
	int	i;
	int	sign;
	int	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9' && i < size)
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * sign);
}

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*ptr;

	len = 0;
	while (src[len] && src[len] != '\n' && src[len] != -1)
		len++;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		exit(0);
	i = 0;
	while (i < len)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
