/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 20:04:48 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/20 20:09:21 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int	issep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	isword(char c, char prevc, char *charset)
{
	return (!issep(c, charset) && issep(prevc, charset));
}

int	nbwords(char *str, char *charset)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (isword(str[i], str[i - 1], charset)
			|| (!issep(str[i], charset) && i == 0))
			size++;
		i++;
	}
	return (size);
}

int	*lenwords(char *str, char *charset)
{
	int	index;
	int	i;
	int	size;
	int	*wordsizes;

	i = 0;
	size = nbwords(str, charset);
	wordsizes = malloc(size * sizeof(int));
	while (i <= size)
	{
		wordsizes[i] = 0;
		i++;
	}
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (!issep(str[i], charset))
			wordsizes[index]++;
		else if (i > 0 && !issep(str[i - 1], charset))
			index++;
		i++;
	}
	return (wordsizes);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		*lengths;
	int		i;
	int		j;
	int		index;

	i = -1;
	j = 0;
	index = 0;
	lengths = lenwords(str, charset);
	split = malloc(sizeof(char) * (nbwords(str, charset) + 1));
	while (str[++i])
	{
		if (!issep(str[i], charset))
		{
			if (i == 0 || isword(str[i], str[i - 1], charset))
				split[index] = malloc(lengths[index] * sizeof(char));
			split[index][j] = str[i];
			split[index][++j] = '\0';
		}
		else if (i > 0 && !issep(str[i - 1], charset) && ++index)
			j = 0;
	}
	split[nbwords(str, charset)] = 0;
	return (split);
}
