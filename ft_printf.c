/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:01:07 by jeshin            #+#    #+#             */
/*   Updated: 2023/12/07 20:07:17 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_format(const char **str, va_list *ap, int *va_num)
{
	(*str)++;
	(*va_num)++;
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
}

void	treate_unsigned_char(const char *str, int *num)
{
	char *tmp;
	int		count;
	int		is_digit;

	is_digit = 0;
	count = 0;
	tmp = (char *)(str + 1);
	(*num)++;
	if (*tmp == '\\' || *tmp == '\n' || *tmp == 't' || *tmp == 'r')
	{
		ft_strlcpy(tmp,str,2);
		ft_putstr_fd(tmp,1);
		return ;
	}
	while (ft_isdigit(*tmp))
	{
		if(count == 3)
			break;
		if(!is_digit)
			is_digit = 1;
		count++;
		tmp++;
	}
	ft_strlcpy(tmp,str,count+1);
	ft_putstr_fd(tmp,1);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			num;

	va_start (ap,str);
	num = 0;
	while (*str)
	{
		if (*str != '%')
		{
			num++;
			ft_putchar_fd(*str, 1);
		}
		else if(*str == '%')
			print_format(&str, &ap, &num);
		str++;
	}
	va_end(ap);
	return (num);
}