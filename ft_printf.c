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

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	buf[1024];
	int		num;
	char	*ret;
	char	*type_each;

	//get variadic num
	num = get_num_va(str);

	//initialize va_list
	va_start (ap,num);

	//copy str to buf
	while((ret = va_arg(ap,int)))
	{
		//write to strout
		put_nbr(ret);
	}
	va_end(ap);
}