/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:07:40 by kbrauer           #+#    #+#             */
/*   Updated: 2023/09/28 15:07:43 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexlen_void(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char	*checkhex(int up)
{
	if (up == 0)
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

static int	ft_puthex_void(unsigned long nb, int up)
{
	int		i;
	int		count;
	char	*hex;
	char	*ptr;

	hex = checkhex(up);
	i = ft_hexlen_void(nb);
	ptr = (char *) malloc (sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = 0;
	i--;
	if (nb == 0)
		ptr[0] = hex[0];
	while (nb)
	{
		ptr[i] = hex[nb % 16];
		nb = nb / 16;
		i--;
	}
	count = ft_putstr(ptr);
	free(ptr);
	return (count);
}

int	ft_voidptr(void *ptr)
{
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	ft_putchar('0');
	ft_putchar('x');
	return (2 + ft_puthex_void((unsigned long)ptr, 0));
}
