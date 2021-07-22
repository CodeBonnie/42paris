/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 11:24:29 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/09 11:24:36 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	newnb;

	if (nb < 0)
	{
		ft_putchar('-');
		newnb = nb * -1;
	}
	else
		newnb = nb;
	if (newnb / 10 != 0)
		ft_putnbr(newnb / 10);
	ft_putchar(newnb % 10 + '0');
}
