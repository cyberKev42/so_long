/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:39:45 by kbrauer           #+#    #+#             */
/*   Updated: 2023/09/20 12:39:47 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_checkref(const char *str, int count, int i, va_list lst)
{
	while (str[i])
	{
		if (str[i] != '%')
			count = count + ft_putchar(str[i--]);
		else if (str[i + 1] == 'c')
			count = count + ft_putchar(va_arg(lst, int));
		else if (str[i + 1] == 's')
			count = count + ft_putstr(va_arg(lst, char *));
		else if (str[i + 1] == 'p')
			count = count + ft_voidptr(va_arg(lst, void *));
		else if (str[i + 1] == 'd')
			count = count + ft_putnbr(va_arg(lst, int));
		else if (str[i + 1] == 'i')
			count = count + ft_putnbr(va_arg(lst, int));
		else if (str[i + 1] == 'u')
			count = count + ft_putnbr_unsigned(va_arg(lst, unsigned int));
		else if (str[i + 1] == 'x')
			count = count + ft_puthex(va_arg(lst, unsigned int), 0);
		else if (str[i + 1] == 'X')
			count = count + ft_puthex(va_arg(lst, unsigned int), 1);
		else if (str[i + 1] == '%')
			count = count + ft_putchar('%');
		i += 2;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	lst;

	if (!str)
		return (0);
	va_start(lst, str);
	count = ft_checkref(str, 0, 0, lst);
	va_end(lst);
	return (count);
}
/*
int	main(void)
{
	char	c = 'C';
	//char	string[] = "string";
	void	*ptr = NULL;
	int	integ = -432;
	unsigned int	unint = 1234;
	int hex = 1234;
	
	printf(" NULL %s NULL ", NULL);
	ft_printf(" NULL %s NULL ", NULL);
	
}
*/
