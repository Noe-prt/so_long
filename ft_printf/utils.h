/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:51:29 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/10 15:34:22 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "Libft/libft.h"

int	ft_putptr(void *ptr, int first);
int	ft_putnbr_custom(int n);
int	ft_putstr_custom(char *s);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned int num, int is_upper);

#endif
