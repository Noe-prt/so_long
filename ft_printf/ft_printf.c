/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:17:44 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/13 11:45:38 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	char	type;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			type = str[i + 1];
			count += put_format(args, type);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	put_format(va_list args, char type)
{
	int	count;

	count = 0;
	if (type == 'd' || type == 'i')
		count += ft_putnbr_custom((int) va_arg(args, int));
	else if (type == 'c' || type == '%')
	{
		if (type == 'c')
			ft_putchar_fd((int) va_arg(args, int), 1);
		else
			ft_putchar_fd('%', 1);
		count++;
	}
	else if (type == 's')
		count += ft_putstr_custom((char *) va_arg(args, char *));
	else if (type == 'p')
		count += ft_putptr((void *) va_arg(args, void *), 0);
	else if (type == 'u')
		count += ft_putunsigned((unsigned int) va_arg(args, unsigned int));
	else if (type == 'x')
		count += ft_puthex((unsigned int) va_arg(args, unsigned int), 0);
	else if (type == 'X')
		count += ft_puthex((unsigned int) va_arg(args, unsigned int), 1);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int value = ft_printf(" %d ", 17);
	ft_printf("%d", value);
	return (0);
}
*/
