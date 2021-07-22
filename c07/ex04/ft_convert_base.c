/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 15:20:19 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/20 17:02:41 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	isforbchar(char c);
int	ft_strlen(char *str);
int	validbase(char *str);
int	isinbase(char c, char *base);
int	lengthinbase(int nbr, char *base);

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nbr;
	int	mincnt;

	i = 0;
	nbr = 0;
	mincnt = 0;
	if (!validbase(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			mincnt++;
	}
	while (isinbase(str[i], base))
	{
		nbr = nbr * ft_strlen(base) + (isinbase(str[i], base) - 1);
		i++;
	}
	if (mincnt % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

char	*ft_itoa_base(int nb, char *base)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = lengthinbase(nb, base);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[0] = base[0];
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = base[(n % ft_strlen(base))];
		n = n / ft_strlen(base);
		i--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	x;

	if (validbase(base_from) && validbase(base_to))
	{
		x = ft_atoi_base(nbr, base_from);
		return (ft_itoa_base(x, base_to));
	}
	else
		return (NULL);
}
