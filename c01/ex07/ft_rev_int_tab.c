/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 16:34:35 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/04 16:35:01 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		n;

	i = 0;
	n = size - 1;
	while (i < (size / 2))
	{	
		ft_swap(&tab[i], &tab[n]);
		i++;
		n--;
	}
}
