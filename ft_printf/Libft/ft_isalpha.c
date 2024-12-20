/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:55:31 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 10:51:17 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_isalpha('c'))
		write(1, "1.S\n", 4);
	else
		write(1, "1.F\n", 4);
	if (ft_isalpha('G'))
		write(1, "2.S\n", 4);
	else
		write(1, "2.F\n", 4);
	if (ft_isalpha('?'))
		write(1, "3.F\n", 4);
	else
		write(1, "3.S\n", 4);
}
*/
