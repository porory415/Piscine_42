/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:22:37 by johyyoon          #+#    #+#             */
/*   Updated: 2022/06/09 21:47:50 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>

int		ft_atoi(char *str);
void	to_oper(int a, int b, char op);
void	ft_putnbr(int nb);
int		add(int n1, int n2);
int		sub(int n1, int n2);
int		multiply(int n1, int n2);
int		divide(int n1, int n2);
int		modular(int n1, int n2);

#endif
