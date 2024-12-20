/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:25:27 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:51:47 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_isdigit('2'))
		write(1, "1.S\n", 4);
	else
		write(1, "1.F\n", 4);
	if (ft_isdigit('9'))
		write(1, "2.S\n", 4);
	else
		write(1, "2.F\n", 4);
	if (ft_isdigit('a'))
		write(1, "3.F\n", 4);
	else
		write(1, "3.S\n", 4);
}
*/
