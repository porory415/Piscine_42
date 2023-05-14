/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:33:43 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/25 12:48:10 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	show_hex(unsigned char c)
{
	char	arr[3];

	arr[0] = "0123456789abcdef"[c / 16];
	arr[1] = "0123456789abcdef"[c % 16];
	write (1, arr, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] >= 32 && str[idx] <= 127)
			write (1, &str[idx], 1);
		else
		{
			write (1, "\\", 1);
			show_hex((unsigned char)str[idx]);
		}
		idx++;
	}
}
