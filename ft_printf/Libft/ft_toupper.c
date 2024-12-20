/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:48:51 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:53:25 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
#include <unistd.h>

int main(void)
{
    char c = 'b';
    char upper = ft_toupper(c);
    write(1, &upper, 1);
    write(1, "\n", 1);
    return (0);
}
*/
