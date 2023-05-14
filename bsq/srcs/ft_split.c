/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:22:27 by gaeokim           #+#    #+#             */
/*   Updated: 2022/06/07 18:55:20 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_split(char c)
{
	if (c == '\n' || c == '\0' || c == -1)
		return (1);
	else
		return (0);
}

int	word_count(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (!is_split(str[i]) && is_split(str[i + 1]))
			count++;
	return (count);
}

void	word_split(char **arr, char *str, int *offset)
{
	int	count;
	int	i;
	int	j;

	while (is_split(str[*offset]))
		(*offset)++;
	(*offset)--;
	count = 0;
	while (!is_split(str[++(*offset)]))
		count++;
	*arr = (char *)malloc(sizeof(char) * (count + 1));
	if (!*arr)
		exit(0);
	i = *offset - count;
	j = 0;
	while (i < *offset)
		(*arr)[j++] = str[i++];
	(*arr)[j] = '\0';
}

char	**ft_split(char *str)
{
	char	**arr;
	int		num_word;
	int		i;
	int		offset;

	num_word = word_count(str);
	arr = (char **)malloc(sizeof(char *) * (num_word + 1));
	if (!arr)
		return (0);
	i = -1;
	offset = 0;
	while (++i < num_word)
		word_split(&(arr[i]), str, &offset);
	arr[i] = (char *)0;
	return (arr);
}
