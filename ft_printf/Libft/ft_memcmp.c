/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:45:28 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:38:03 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (n > 0 && *us1 == *us2)
	{
		us1++;
		us2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*us1 - *us2);
}
/*
#include <stdio.h>

int main(void)
{
    char s1[6] = "he\0llo";
    char s2[6] = "he\220llo";
    int result = ft_memcmp(s1, s2, 2);
    printf("%d\n", result);
    return (0);
}
*/
