/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:04:27 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/05 20:24:55 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*str_dup(char *s)
{
	int		i;
	int		len;
	char	*ret;

	len = str_len(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;
	char		*s;

	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	i = 0;
	while (i < ac)
	{
		s = av[i];
		ret[i].size = str_len(s);
		ret[i].str = s;
		ret[i].copy = str_dup(s);
		i++;
	}
	ret[ac].str = 0;
	return (ret);
}
