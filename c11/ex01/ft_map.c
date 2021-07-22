/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 19:52:06 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/21 19:52:07 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*ntab;

	ntab = malloc(sizeof(int) * length);
	if (!ntab)
		return (0);
	i = 0;
	while (i < length)
	{
		ntab[i] = (*f)(tab[i]);
		i++;
	}
	return (ntab);
}
