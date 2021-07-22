/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:23:45 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/08 19:23:51 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0 )
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	sizesrc;
	unsigned int	sizedest;

	sizesrc = ft_strlen(src);
	sizedest = ft_strlen(dest);
	i = sizedest;
	if (size != 0 && size > sizedest)
	{
		while (i < size - 1 && src[i - (sizedest)])
		{
			dest[i] = src[i - (sizedest)];
			i++;
		}
		dest[i] = '\0';
		return ((sizesrc + sizedest));
	}
	else
		return ((sizesrc + size));
}
