/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:27:18 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/07 18:02:42 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		i;

	i = 0;
	while (src[i])
	{
		if (i < size - 1 )
		{
			dest[i] = src[i];
		}
		i++;
	}
	if (i > size - 1)
	{
		dest[size - 1] = '\0';
	}
	else
	{
		dest[i] = '\0';
	}
	return (i);
}
