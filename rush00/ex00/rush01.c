/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:44:32 by jroux-fo          #+#    #+#             */
/*   Updated: 2021/07/04 16:59:33 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	affichage(int i, int j, int x, int y)
{
	if ((i == 1 && j == 1) || (i == x && j == y && j != 1 && i != 1))
		ft_putchar('/');
	else if ((i == 1 && j == y) || (i == x && j == 1))
		ft_putchar('\\');
	else if ((i < x && i > 1) && (j == 1 || j == y))
		ft_putchar('*');
	else if ((j < y && j > 1) && (i == 1 || i == x))
		ft_putchar('*');
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
