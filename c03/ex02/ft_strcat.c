/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:22:32 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/08 19:22:37 by bnicolas         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	sizesrc;
	int	sizedest;

	sizesrc = ft_strlen(src);
	sizedest = ft_strlen(dest);
	i = sizedest;
	while (i < sizesrc + sizedest)
	{
		dest[i] = src[i - (sizedest)];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
