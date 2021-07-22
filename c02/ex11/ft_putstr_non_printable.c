/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:11:40 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/07 18:12:34 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	charhex(int x)
{
	if (x >= 0)
	{
		if (x < 10)
		{
			return ('0' + x);
		}
		else if (x < 16)
		{
			return ('a' + (x % 10));
		}
	}
	return ('\0');
}

void	charhexwriter(int x)
{
	char	a;
	char	b;

	b = charhex(x % 16);
	x = x / 16;
	a = charhex(x % 16);
	x = x / 16;
	write(1, &a, 1);
	write(1, &b, 1);
}

int	ft_str_is_printable(char c)
{
	if ((c >= 0 && c <= 31) || c == 127)
	{
		return (0);
	}
	return (1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 92;
	while (str[i])
	{
		if (ft_str_is_printable(str[i]))
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, &c, 1);
			charhexwriter(0 + str[i]);
		}
		i++;
	}
}
