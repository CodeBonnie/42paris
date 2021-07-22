/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:01:54 by masamoil          #+#    #+#             */
/*   Updated: 2021/07/03 11:44:23 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	affichage(int i, int j, int x, int y)
{
	if ((i == 1 && j == 1) || (i == x && j == 1)
		|| (i == 1 && j == y) || (i == x && j == y))
		ft_putchar('o');
	else if ((i < x && i > 1) && (j == 1 || j == y))
		ft_putchar('-');
	else if ((j < y && j > 1) && (i == 1 || i == x))
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (y > 0 && x > 0)
	{
		while (j <= y)
		{
			while (i <= x)
			{
				affichage(i, j, x, y);
				i++;
			}
			ft_putchar('\n');
			i = 1;
			j++;
		}
	}
}
