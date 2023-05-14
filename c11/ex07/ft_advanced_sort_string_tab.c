/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:30:55 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/09 15:33:52 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*swp;
	int		i;
	int		k;

	i = 0;
	while (tab[i])
	{
		k = 0;
		while (tab[k] && tab[k + 1])
		{
			if ((*cmp)(tab[k], tab[k + 1]) > 0)
			{
				swp = tab[k];
				tab[k] = tab[k + 1];
				tab[k + 1] = swp;
			}
			k++;
		}
		i++;
	}
}
