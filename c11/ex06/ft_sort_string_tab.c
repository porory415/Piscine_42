/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:30:58 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/09 17:18:48 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		k;
	char	*swp;

	i = 0;
	while (tab[i])
	{
		k = i + 1;
		while (tab[k])
		{
			if (ft_strcmp(tab[i], tab[k]) > 0)
			{
				swp = tab[i];
				tab[i] = tab[k];
				tab[k] = swp;
			}
			k++;
		}
		i++;
	}
}
