/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 09:02:03 by smercado          #+#    #+#             */
/*   Updated: 2024/07/08 10:11:48 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_pointer(unsigned long long n, int *count)
{
	if (n >= 16)
	{
		print_pointer((n / 16), count);
		print_pointer((n % 16), count);
	}
	else
		ft_puthexaminus(n, count);
}

void	ft_putpointer(void *p, int *count)
{
	unsigned long long	pointer;

	pointer = (unsigned long long)p;
	if (!p)
		ft_putstrplus("(nil)", count);
	else
	{
		ft_putstrplus("0x", count);
		print_pointer(pointer, count);
	}
}
