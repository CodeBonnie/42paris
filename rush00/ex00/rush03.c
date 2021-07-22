/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroux-fo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 22:08:52 by jroux-fo          #+#    #+#             */
/*   Updated: 2021/07/03 12:09:29 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	affichage(int i, int j, int x, int y)
{
	if ((i == 1 && j == 1) || (i == 1 && j == y))
		ft_putchar('A');
	else if ((i == x && j == 1) || (i == x && j == y))
		ft_putchar('C');
	else if ((i < x && i > 1) && (j == 1 || j == y))
		ft_putchar('B');
	else if ((j < y && j > 1) && (i == 1 || i == x))
		ft_putchar('B');
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
