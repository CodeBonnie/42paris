/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:17:26 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/21 20:28:23 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 1;
	if (length == 1)
		return (1);
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) < 0)
			break ;
		i++;
	}
	if (i == length)
		return (1);
	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i - 1], tab[i]) > 0)
			break ;
		i++;
	}
	if (i == length)
		return (1);
	return (0);
}
