/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:01:07 by jeshin            #+#    #+#             */
/*   Updated: 2023/12/07 17:16:06 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_format(const char **str,va_list *ap){
	int	err_is;

	err_is = 0;
	(*str)++;
	if (**str =='c')
		ft_putchar_fd(va_arg(*ap,int),1);
	else if (**str == 's')
		ft_putstr_fd(va_arg(*ap,char *),1);
	else if (**str == 'd')
		ft_putnbr_fd(va_arg(*ap,int),1);
	else if (**str == 'i')
		ft_putnbr_fd(va_arg(*ap,int),1);
	else if (**str == 'p')
		ft_putaddr_fd(va_arg(*ap,void *),1);
	else if (**str == 'u')
		ft_putnbr_fd(va_arg(*ap,unsigned int),1);
	else if (**str == 'x')
		ft_puthex_fd(va_arg(*ap,int),1,0);
	else if (**str == 'X')
		ft_puthex_fd(va_arg(*ap,int),1,1);
	else if (**str == '%')
		ft_putchar_fd('%',1);
	else
		ft_putchar_fd(**str,1);
	if(err_is == 1)
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	va_start (ap,str);
	while (*str)
	{
		if (*str != '%')
			ft_putchar_fd(*str,1);
		else
			if (!print_format(&str, &ap))
				return (-1);
		str++;
	}
	va_end(ap);
	return (1);
}