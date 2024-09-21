/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beboccas <beboccas@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:50:38 by beboccas          #+#    #+#             */
/*   Updated: 2023/10/22 17:50:38 by beboccas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*b;

	a = c;
	b = (char *)s;
	while (*b)
	{
		if (*b == a)
			return (b);
		b++;
	}
	if (!a)
		return (b);
	return (NULL);
}

void	check_param(const char *str, va_list args, int *i)
{
	if (*str == 'c')
		(*i) += ft_print_char(va_arg(args, int));
	else if (*str == 's')
		(*i) += ft_print_str(va_arg(args, char *));
	else if (*str == 'p')
		ft_print_pointer(va_arg(args, size_t), i);
	else if (*str == 'd' || *str == 'i')
		(*i) += ft_print_int(va_arg(args, int));
	else if (*str == 'u')
		(*i) += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (*str == 'x')
		ft_put_digit(va_arg(args, long long int), 16, i);
	else if (*str == 'X')
		ft_put_upper_digit(va_arg(args, long long int), 16, i);
	else if (*str == '%')
		(*i) += ft_print_char('%');
	else
		(*i)--;
}

int	ft_printf(char const *str, ...)
{
	int		total_size;
	va_list	args;

	total_size = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (ft_strchr("cspdiuxX%%", *++str))
				check_param(str++, args, &total_size);
		}
		else
			total_size += ft_print_char(*str++);
	}
	va_end(args);
	return (total_size);
}
