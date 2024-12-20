/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:08:17 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/06 13:40:00 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*new_str;

	i = 0;
	new_str = malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
/*
#include <stdio.h>

int	main(void)
{
	const char str[5] = "hello";
	char *dest = ft_strdup(str);
	printf("%s", dest);
	return (0);
}
*/
