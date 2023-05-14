/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:07:17 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/07 19:13:41 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*empty_str(void)
{
	char	*empty_arr;

	empty_arr = (char *)malloc(1);
	empty_arr[0] = '\0';
	return (empty_arr);
}

int	ft_str_len(char *str)
{
	int	k;

	k = 0;
	while (str[k] != '\0')
		k++;
	return (k);
}

int	get_malloc_size(int size, char **str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_str_len(str[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;
	int		i;
	int		j;
	int		k;
	int		len;

	if (size <= 0)
		return (empty_str());
	len = get_malloc_size(size, strs) + ft_str_len(sep) * (size - 1);
	i = -1;
	k = 0;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			arr[k++] = strs[i][j++];
		j = 0;
		while (i != size - 1 && sep[j] != '\0')
			arr[k++] = sep[j++];
	}
	arr[k] = '\0';
	return (arr);
}
