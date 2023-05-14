/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:42:36 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/24 15:38:02 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	is_space;
	int	idx;

	is_space = 1;
	idx = 0;
	while (str[idx])
	{
		if (is_space == 1 && (str[idx] >= 'a' && str[idx] <= 'z'))
			str[idx] -= 32;
		else if (is_space == 0 && (str[idx] >= 'A' && str[idx] <= 'Z'))
			str[idx] += 32;
		if ((str[idx] >= 'a' && str[idx] <= 'z')
			|| (str[idx] >= 'A' && str[idx] <= 'Z')
			|| (str[idx] >= '0' && str[idx] <= '9'))
			is_space = 0;
		else
			is_space = 1;
		idx++;
	}
	return (str);
}
