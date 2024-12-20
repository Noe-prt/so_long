/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:53:35 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:52:44 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_isascii('c'))
		write(1, "1.S\n", 4);
	else
		write(1, "1.F\n", 4);
	if (ft_isascii('5'))
		write(1, "2.S\n", 4);
	else
		write(1, "2.F\n", 4);
	if (ft_isascii(200))
		write(1, "3.F\n", 4);
	else
		write(1, "3.S\n", 4);
}
*/
