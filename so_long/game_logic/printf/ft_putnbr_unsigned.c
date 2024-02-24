/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:36:11 by kbrauer           #+#    #+#             */
/*   Updated: 2023/09/23 16:36:13 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	char	new_nb;
	int		count;

	count = 0;
	if (nb < 10)
	{
		new_nb = nb + 48;
		write(1, &new_nb, 1);
		count++;
	}
	else
	{
		count = 1 + ft_putnbr_unsigned(nb / 10);
		new_nb = (nb % 10) + 48;
		write(1, &new_nb, 1);
	}
	return (count);
}
