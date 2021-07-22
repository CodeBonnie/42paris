/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:58:34 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/02 14:44:23 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	printComb(int a, int b)
{
	char	c;

	c = '0';
	ft_putchar(a / 10 + c);
	ft_putchar(a % 10 + c);
	ft_putchar(' ');
	ft_putchar(b / 10 + c);
	ft_putchar(b % 10 + c);
	if (a != 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;

	a = 0;
	b = a + 1;
	while (a < b)
	{
		b = a + 1;
		while (b <= 99)
		{
			printComb(a, b);
			b++;
		}
		a++;
	}
}
