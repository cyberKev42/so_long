/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:18:26 by kbrauer           #+#    #+#             */
/*   Updated: 2023/09/21 18:18:28 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*checkhex(int up)
{
	if (up == 0)
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

int	ft_puthex(unsigned int nb, int up)
{
	int		i;
	int		count;
	char	*hex;
	char	*ptr;

	hex = checkhex(up);
	i = ft_hexlen(nb);
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
