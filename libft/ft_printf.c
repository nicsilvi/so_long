/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smercado <smercado@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 08:52:36 by smercado          #+#    #+#             */
/*   Updated: 2024/09/04 09:14:19 by smercado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
tener en cuenta, cantidad de argumetos
si empieza en % o para ft_putchar

return un int para buscar errores (int neg para errores,
o num of caracteres printed).
se incializan los argumentos con type va_list using va_start.
llamando va_arg te va dando los argumentos. va_end indica cuando para.


*/
void	ft_putstrplus(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstrplus("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_putcharplus(str[i], count);
		i++;
	}
}

void	ft_putcharplus(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_findtype(va_list argument, char format, int *count)
{
	if (format == 'c')
		ft_putcharplus(va_arg(argument, int), count);
	else if (format == 's')
		ft_putstrplus(va_arg(argument, char *), count);
	else if (format == 'p')
		ft_putpointer(va_arg(argument, void *), count);
	else if (format == 'd' || format == 'i')
		ft_putnumber(va_arg(argument, int), count);
	else if (format == 'u')
		ft_putunsigned(va_arg(argument, unsigned int), count);
	else if (format == 'x')
		ft_puthexaminus(va_arg(argument, unsigned int), count);
	else if (format == 'X')
		ft_puthexamayus(va_arg(argument, unsigned int), count);
	else if (format == '%')
		ft_putcharplus('%', count);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	arguments;

	va_start(arguments, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putcharplus(str[i], &count);
		else if (str[i] == '%')
		{
			i++;
			ft_findtype(arguments, str[i], &count);
		}
		i++;
	}
	va_end(arguments);
	return (count);
}
