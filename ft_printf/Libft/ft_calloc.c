/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:00:44 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/07 21:14:04 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
/*
#include <stdio.h>

int	main(void)
{
	char* str;

	str = ft_calloc(5, sizeof(char));
	if (str == NULL)
	{
		printf("Allocation failed!");
		return (0);
	}
	else
		printf("memory was allocated successfully\n");
	for (int i = 0; i < 5; i++)
	{
		str[i] = 'c';
	}
	printf("%s", str);
	return (0);
}
*/
