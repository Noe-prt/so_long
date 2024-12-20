/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:59:43 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:59:47 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_numbers(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*set_memory(size_t length)
{
	char	*str;

	str = malloc(length * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[length] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	size_t	i;
	size_t	length;

	nbr = n;
	length = count_numbers(nbr);
	str = set_memory(length);
	i = length - 1;
	if (nbr == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
/*
int main(void)
{
    char *nbr = ft_itoa(-2147483648);
    printf("%s\n", nbr);
    free(nbr);
    return 0;
}
*/
