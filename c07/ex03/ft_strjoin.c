/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 16:07:52 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/20 14:57:42 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

unsigned int	ft_arrstr_len(char **strs, char *sep, int size)
{
	int				i;
	unsigned int	count;

	if (size <= 0)
		return (0);
	count = 0;
	i = 0;
	while (strs[i])
		count += ft_strlen(strs[i++]);
	count = count + (ft_strlen(sep) * (size - 1));
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int				i;
	unsigned int	len;
	char			*joined;

	if (size <= 0)
		size = 0;
	len = ft_arrstr_len(strs, sep, size) + 1;
	joined = malloc(sizeof(char) * len);
	if (!joined)
		return (0);
	i = 0;
	joined[0] = '\0';
	while (i < size)
	{
		ft_strlcat(joined, strs[i], len);
		if (i + 1 != size)
			ft_strlcat(joined, sep, len);
		i++;
	}
	return (joined);
}
