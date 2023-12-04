/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:01:07 by jeshin            #+#    #+#             */
/*   Updated: 2023/11/28 20:24:13 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_num_va(const char *str)
{
	int num;

	num = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) && *(str + 1) != 'c')
				num++;
		}
		str++;
	}
	return (num);
}

int check_format(const char **str,va_list *ap){
	int base;

	base = 0;
	(*str)++;
	if (**str =='c')
		va_arg(*ap, char);
	else if (**str == 's')
		va_arg(*ap, const char *);
	else if (**str == 'd' || **str == 'i')
		va_arg(*ap, int);
	else if (**str == 'p')
		va_arg(*ap, void *);
	else if (**str == 'u')
		va_arg(*ap, unsigned int);
	else if (**str == 'x')
		va_arg(*ap, int);
	else if (**str == 'X')
		va_arg(*ap, int);
	else if (**str == '%')
		ft_putchar('%');
	else
	(*str)++;

	if(base == 10)
	else if(base == 16)
	

	//cspdiuxX%
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	va_start (ap,str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar(str);
		else
		{
			if (check_format(&str, &ap))
				;//print();
		}
		str++;
	}
	va_end(ap);
}