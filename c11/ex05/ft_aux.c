/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:27:16 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/22 14:42:02 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aux.h"
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 )
	{
		write(1, &str[i], 1);
		i++;
	}
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

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	mincnt;

	i = 0;
	nbr = 0;
	mincnt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mincnt++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (mincnt % 2 == 1)
		return (nbr * -1);
	return (nbr);
}
