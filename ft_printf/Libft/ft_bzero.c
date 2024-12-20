/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:20:24 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:07:16 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = (char *) s;
	while (n > 0)
	{
		*temp = 0;
		temp++;
		n--;
	}
}

/*
#include <unistd.h>

int main(void)
{
	write(1, "Avant appel:\n", 13);
	char array[5] = "Hello";
	write(1, array, 5);
	write(1, "\n", 1);
	ft_bzero(array, 3);
	write(1, "Apres appel:\n", 13);
	write(1, array, 5);
	write(1, "\n", 1);
}
*/
