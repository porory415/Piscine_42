/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:31:02 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/09 16:54:43 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	k;
	int	count;

	k = 0;
	count = 0;
	while (k < length)
	{
		if ((*f)(tab[k]))
		{
			count++;
		}
		k++;
	}
	return (count);
}
