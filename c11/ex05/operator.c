/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:05:37 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/09 15:13:55 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	add(int n1, int n2)
{
	return (n1 + n2);
}

int	sub(int n1, int n2)
{
	return (n1 - n2);
}

int	multiply(int n1, int n2)
{
	return (n1 * n2);
}

int	divide(int n1, int n2)
{
	return (n1 / n2);
}

int	modular(int n1, int n2)
{
	return (n1 % n2);
}
