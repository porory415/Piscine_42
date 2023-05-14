/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:08:41 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/07 19:17:03 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *nbr, char *base_from, int f_base_len);
char	*ft_itoa_base(int nbr, char *base_to, int t_base_len);

int	ft_base_check(char *str)
{
	int	len;
	int	idx;

	len = 0;
	while (str[len] != '\0')
	{
		idx = 0;
		if (str[len] == '+' || str[len] == '-')
			return (-1);
		if ((9 <= str[len] && str[len] <= 13) || str[len] == ' ')
			return (-1);
		while (idx < len)
		{
			if (str[idx] == str[len])
				return (-1);
			idx++;
		}
		len++;
	}
	if (len <= 1)
		return (-1);
	return (len);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	fb_len;
	int	tb_len;
	int	argu_to_itoa;

	fb_len = ft_base_check(base_from);
	tb_len = ft_base_check(base_to);
	if (fb_len == -1 || tb_len == -1)
		return (0);
	argu_to_itoa = ft_atoi_base(nbr, base_from, fb_len);
	return (ft_itoa_base(argu_to_itoa, base_to, tb_len));
}
