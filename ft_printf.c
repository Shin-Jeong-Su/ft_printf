/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:01:07 by jeshin            #+#    #+#             */
/*   Updated: 2023/12/09 19:00:41 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_str(va_list *ap, int *num)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (str == 0)
		*num += ft_putstr("(null)");
	else
		*num += ft_putstr(str);
	return (0);
}

void	print_format(const char **str, va_list *ap, int *num)
{
	if (**str == 'c')
		*num += ft_putchar(va_arg(*ap, int));
	else if (**str == 's')
		check_str(ap, num);
	else if (**str == 'd')
		ft_putnbr_cnt(va_arg(*ap, int), num);
	else if (**str == 'i')
		ft_putnbr_cnt(va_arg(*ap, int), num);
	else if (**str == 'p')
		ft_putaddr_cnt(va_arg(*ap, void *), num);
	else if (**str == 'u')
		ft_putnbr_unsigned(va_arg(*ap, unsigned int), num);
	else if (**str == 'x')
		ft_puthex_cnt(va_arg(*ap, unsigned int), 0, num);
	else if (**str == 'X')
		ft_puthex_cnt(va_arg(*ap, unsigned int), 1, num);
	else if (**str == '%')
		*num += ft_putchar('%');
	else
		*num += ft_putchar(**str);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			num;

	va_start (ap, str);
	num = 0;
	while (*str)
	{
		if (*str != '%')
			num += ft_putchar(*str);
		else if (*str == '%')
		{
			str++;
			print_format(&str, &ap, &num);
		}
		str++;
	}
	va_end(ap);
	return (num);
}
