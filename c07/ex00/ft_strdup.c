/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:06:45 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/07 19:13:50 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*arr;
	int		length;
	int		i;

	length = ft_strlen(src);
	arr = (char *)malloc(length + 1);
	i = 0;
	while (i < length)
	{
		arr[i] = src[i];
		i++;
	}
	arr[length] = '\0';
	return (arr);
}
