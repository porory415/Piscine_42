/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toptr_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:13:02 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/09 22:01:13 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	to_oper(int a, int b, char op)
{
	static int	(*f[5])(int, int) = {add, sub, multiply, divide, modular};
	static char	oper[6] = "+-*/%";
	int			i;

	i = 0;
	while (i < 5)
	{
		if (oper[i] == op)
		{
			if (op == '/' && b == 0)
				write (1, "Stop : division by zero", 24);
			else if (op == '%' && b == 0)
				write (1, "Stop : modulo by zero", 22);
			else
				ft_putnbr((*f[i])(a, b));
		}
		i++;
	}
	write (1, "\n", 1);
}
