/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:24:10 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/07 17:49:59 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

int	is_alphanumeric(char c)
{
	if (
		((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z'))
		|| (c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if (is_alphanumeric(str[i]))
		{
			if ((str[i] >= 'a' && str[i] <= 'z'))
			{
				str[i] -= 32;
			}
			while (is_alphanumeric(str[i]))
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	return (str);
}
