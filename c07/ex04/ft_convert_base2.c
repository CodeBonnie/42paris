/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:02:57 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/20 17:03:04 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isforbchar(char c)
{
	if (c <= 32 || c == 127
		|| c == '+' || c == '-')
		return (1);
	return (0);
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

int	isinbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i + 1);
		i++;
	}
	return (0);
}

int	lengthinbase(int nbr, char *base)
{
	unsigned int	newnb;
	int				baselen;
	int				countbase;

	countbase = 0;
	if (validbase(base))
	{
		baselen = ft_strlen(base);
		if (nbr < 0)
		{
			countbase++;
			newnb = nbr * -1;
		}
		else
			newnb = nbr;
		countbase++;
		if (newnb / baselen != 0)
			countbase += lengthinbase(newnb / baselen, base);
		return (countbase);
	}
	else
		return (-1);
}
