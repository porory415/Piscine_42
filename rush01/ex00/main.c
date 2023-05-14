/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 15:14:58 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/29 16:32:40 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	g_error;

int	check_prev(char curr, char prev)
{
	if (prev > '0' && prev <= '4')
	{
		if (cur != ' ')
			return (0);
	}
	else if (prev == ' ')
	{
		if (curr <= '0' || curr > '4')
			return (0);
	}
	else
		return (0);
	return (1);
}

int	check_input(char *str)
{
	char	*ret_arr;
	int	count;

	ret_arr = str;
	count = 0;
	if (*str >'0' && *str <= '4')
		count++;
	else
		return (1); //1 mean it is error
	str++;
	while (*str != '\0')
	{
		if check_prev(*str, *(str - 1) == 0)
			return (1);
		if (*str != ' ')
			count++;
		if (count == 16 && *(str + 1) != '\0')
			return (1);
		str++;
	}
	if (count != 16)
		return (1);
	get_col_row(ret_arr);
	return (g_error);
}

int	main(int argc, char *argv)
{
	g_error = 0;
	if (argc == 2)
		g_error = check_input(argv[1]);
	else
		g_error = 1;
	if (g_error == 1)
	{
		write(1, "Error\n", 1);
	}
	return	(0);
}