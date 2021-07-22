/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:25:27 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/13 17:25:30 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fact;

	if (nb < 0 )
		return (0);
	fact = 1;
	i = fact;
	while (i <= nb)
	{
		fact = fact * i++;
	}
	return (fact);
}
