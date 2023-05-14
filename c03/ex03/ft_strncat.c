/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:23:10 by johyyoon          #+#    #+#             */
/*   Updated: 2022/05/30 23:06:14 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	int				x;
	int				y;

	x = 0;
	y = 0;
	idx = 0;
	while (dest[x] != '\0')
		x++;
	while (idx < nb && src[y] != '\0')
	{
		dest[x + idx] = src[y];
		idx++;
		y++;
	}
	dest[x + idx] = '\0';
	return (dest);
}
