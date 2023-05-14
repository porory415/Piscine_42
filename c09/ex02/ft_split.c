/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:29:38 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/07 21:26:43 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *str, char *charset, int idx)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (str[idx] == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_split_size(char *str, char *charset)
{
	int	i;
	int	initial;
	int	size;

	i = 0;
	initial = 1;
	size = 0;
	while (str[i] != '\0')
	{
		while (is_charset(str, charset, i))
		{
			i++;
			initial++;
		}
		if (str[i] == '\0')
			break ;
		if (initial)
		{
			size++;
			initial = 0;
		}
		i++;
	}
	return (size);
}

char	*go_malloc(char *ret, char *str, int len, int idx)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ret[i] = str[idx + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	get_length(char *str, char *charset, int idx)
{
	int	i;

	i = 0;
	while (str[i + idx] != '\0')
	{
		if (is_charset(str, charset, i + idx))
			break ;
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		split_size;
	int		i;
	int		j;
	int		len;

	split_size = get_split_size(str, charset);
	arr = (char **)malloc(sizeof(char *) * (split_size + 1));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (is_charset(str, charset, i))
			i++;
		if (str[i] == '\0')
			break ;
		len = get_length(str, charset, i);
		arr[j] = (char *)malloc(sizeof(char) * (len + 1));
		go_malloc(arr[j++], str, len, i);
		i += len;
	}
	arr[j] = 0;
	return (arr);
}
