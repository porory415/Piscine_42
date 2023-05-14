/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:31:00 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/09 17:18:22 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;
	int	ascending;
	int	descending;
	int	correct_case;

	i = -1;
	ascending = 0;
	descending = 0;
	correct_case = ((length - 1) * length) / 2;
	while (++i < length - 1)
	{
		j = i;
		while (++j < length)
		{
			if ((*f)(tab[i], tab[j]) >= 0)
				descending++;
			if ((*f)(tab[i], tab[j]) <= 0)
				ascending++;
		}
	}
	if (ascending == correct_case || descending == correct_case)
		return (1);
	return (0);
}
