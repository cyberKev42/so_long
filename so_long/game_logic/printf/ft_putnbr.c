/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:25:14 by kbrauer           #+#    #+#             */
/*   Updated: 2023/09/21 19:25:16 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_posnbr(int nb, int count)
{
	char	new_nb;

	if (nb < 10)
	{
		new_nb = nb + 48;
		write(1, &new_nb, 1);
		count++;
	}
	else
	{
		count = 1 + ft_posnbr(nb / 10, count);
		new_nb = (nb % 10) + 48;
		write(1, &new_nb, 1);
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	if (nb == -2147483648)
	{
		nb = (nb / 10) * -1;
		write(1, "-", 1);
		count = ft_posnbr(nb, 0);
		write(1, "8", 1);
		count += 2;
	}
	else if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count = ft_posnbr(nb, 0);
		count++;
	}
	else
		count = ft_posnbr(nb, 0);
	return (count);
}
