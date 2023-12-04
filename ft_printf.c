/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:01:07 by jeshin            #+#    #+#             */
/*   Updated: 2023/12/04 21:54:45 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_fd(long int n, int fd,int upper)
{
	long int			l;
	char				*set;

	l = (long int)n;
	if(upper)
		set ="0123456789ABCDEF";
	else
		set = "0123456789abcdef";
	if (l < 0)
	{
		l *= -1;
		write(fd, "-", 1);
	}
	if (l < 16)
		write(fd, &set[l], 1);
	else if(l >= 16)
	{
		ft_puthex_fd(l / 16, 1, upper);
		write(fd, &set[l % 16], 1);
	}
}

void	ft_putaddr_fd(void *addr, int fd)
{
	unsigned long int			l;

	l = (unsigned long int)addr;
	write(fd,"0x",2);
	ft_puthex_fd(l,fd,0);
}

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

// int	check_format(va_list *ap,int type, int base, int case)
// {
// 	if(type == 0 && base == 0 && case == 0)
// 		ft_putchar_fd(va_arg(*ap,char),1);//c
// 	else if(type == 0 && base == 0 && case == 1)
// 		ft_putstr(*ap);//s
// 	else if(base == 10 && case == 0)
// 		ft_putnbr(*ap);//d
// 	else if(base == 10 && case == 0)
// 		ft_putnbr(*ap);//i
// 	else if(base == 16 && case == 0)
// 		ft_putnbr(*ap);//p
// 	else if(base == 10 && case == 0)
// 		ft_putnbr(*ap);//u
// 	else if(base == 16 && case == 0)
// 		ft_putstr(ap);//x
// 	else if(base == 16 && case == 1)
// 		ft_putstr(ap);//X
// 	return (1);
// }

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