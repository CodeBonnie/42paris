/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:04:48 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/12 16:06:05 by bnicolas         ###   ########.fr       */
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
