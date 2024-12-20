/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:57:53 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:53:50 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
#include <unistd.h>

int main(void)
{
    char c = 'B';
    char lower = ft_tolower(c);
    write(1, &lower, 1);
    write(1, "\n", 1);
    return (0);
}
*/
