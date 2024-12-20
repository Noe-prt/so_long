/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:17:39 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/10 15:33:37 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putptr(void *ptr, int first)
{
	unsigned long	num;
	char			*hex;
	int				count;

	count = 0;
	if (!ptr)
		return (ft_putstr_custom("(nil)"));
	if (first == 0)
		count += ft_putstr_custom("0x");
	first++;
	num = (unsigned long)ptr;
	hex = "0123456789abcdef";
	if (num >= 16)
		count += ft_putptr((void *)(num / 16), first);
	ft_putchar_fd(hex[num % 16], 1);
	return (count + 1);
}

int	ft_putnbr_custom(int n)
{
	int		count;
	char	*num;

	count = 0;
	num = ft_itoa(n);
	ft_putstr_fd(num, 1);
	count = ft_strlen(num);
	free(num);
	return (count);
}

int	ft_putstr_custom(char *s)
{
	int	count;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	count = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int				count;
	unsigned int	digit;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsigned(n / 10);
		count += ft_putunsigned(n % 10);
	}
	else
	{
		digit = n + '0';
		write(1, &digit, 1);
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned int num, int is_upper)
{
	char	*hex;
	int		count;

	count = 0;
	if (is_upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num >= 16)
		count += ft_puthex(num / 16, is_upper);
	ft_putchar_fd(hex[num % 16], 1);
	count++;
	return (count);
}
