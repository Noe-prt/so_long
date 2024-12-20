/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:39:19 by nopareti          #+#    #+#             */
/*   Updated: 2024/10/27 15:58:35 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (src == (void *) 0 && dst == (void *) 0)
		return (dst);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (n > 0)
	{
		*tmp_dst = *tmp_src;
		tmp_dst++;
		tmp_src++;
		n--;
	}
	return (dst);
}
/*
#include <unistd.h>

int main(void)
{
    char src[10] = "12345ABCDE";
    char dst[10];
    for (int i = 0; i < 10; i++)
        dst[i] = '.';
    write(1, "Avant ft_memcpy:\n", 17);
    write(1, dst, 10);
    write(1, "\n", 1);
    ft_memcpy(dst, src, 6);
    write(1, "Après ft_memcpy:\n", 17);
    write(1, dst, 10);
    write(1, "\n", 1);
    return (0);
}
*/
