/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:24:51 by smercado          #+#    #+#             */
/*   Updated: 2024/09/04 09:14:30 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	print_number(int n, int *count)
{
	int		i;
	char	*str;

	i = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return ;
	str[i] = '\0';
	while (i -1 >= 0)
	{
		str[i -1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	ft_putstrplus(str, count);
	free(str);
}

void	ft_putnumber(int n, int *count)
{
	if (n == 0)
		ft_putcharplus('0', count);
	else if (n == -2147483648)
		ft_putstrplus("-2147483648", count);
	else if (n > 0)
		print_number(n, count);
	else
	{
		ft_putcharplus('-', count);
		n = -n;
		print_number(n, count);
	}
}
