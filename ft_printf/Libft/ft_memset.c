/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:42:17 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:06:20 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *) b;
	while (len > 0)
	{
		*temp = (unsigned char) c;
		temp++;
		len--;
	}
	return (b);
}

/*
#include <unistd.h>

int	main(void)
{
	char array[10];
	
	for (int i = 0; i < 10; i++)
		array[i] = '.';
	write(1, "Avant ft_memset:\n", 17);
	write(1, array, 10);
	write(1, "\n", 1);
	ft_memset(array, '?', 5);
	write(1, "Après ft_memset:\n", 17);
	write(1, array, 10);
	write(1, "\n", 1);

	return (0);
}
*/
