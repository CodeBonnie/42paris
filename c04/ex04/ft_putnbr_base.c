/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:50:16 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/12 16:06:20 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 )
	{
		i++;
	}
	return (i);
}

int	isforbchar(char c)
{
	if (c <= 32 || c == 127
		|| c == '+' || c == '-')
		return (1);
	return (0);
}

int	validbase(char *str)
{
	int	i;
	int	j;
	int	count;
	int	len;

	len = ft_strlen(str);
	if (len < 2)
		return (0);
	i = 0;
	while (str[i])
	{
		count = 0;
		j = 0;
		if (isforbchar(str[i]))
			return (0);
		while (str[j])
		{
			if (str[i] == str[j++])
				count++;
		}
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	newnb;
	int				baselen;

	if (validbase(base))
	{
		baselen = ft_strlen(base);
		if (nbr < 0)
		{
			ft_putchar('-');
			newnb = nbr * -1;
		}
		else
			newnb = nbr;
		if (newnb / baselen != 0)
			ft_putnbr_base(newnb / baselen, base);
		ft_putchar(base[newnb % baselen]);
	}
}
