/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:36:36 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 11:06:20 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char) *s1 - *s2);
}
/*
#include <stdio.h>

int main(void)
{
    char s1[6] = "hello";
    char s2[6] = "hel!o";
    int result = ft_strncmp(s1, s2, 2);
    printf("%d\n", result);
    return (0);
}
*/
