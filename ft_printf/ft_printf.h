/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:11:57 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/13 11:05:56 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include "Libft/libft.h"
# include "utils.h"

int	ft_printf(const char *str, ...);
int	is_type(char c);
int	put_format(va_list args, char type);

#endif
