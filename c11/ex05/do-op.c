/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:11:12 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/22 14:42:12 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_aux.h"

char	check_argop(char *s)
{
	if (ft_strlen(s) == 1)
	{
		if (BASIC_OP(s[0]) || DIV_OP(s[0]))
			return (s[0]);
	}
	return (0);
}

int	forbiddenop(t_op op)
{
	if (DIV_OP(op.c) && op.y == 0)
	{
		if (op.c == '/')
			ft_putstr("Stop : division by zero");
		else
			ft_putstr("Stop : modulo by zero");
		return (1);
	}
	return (0);
}

void	do_op(t_op op)
{
	if (op.c == '+')
		ft_putnbr(op.x + op.y);
	else if (op.c == '-')
		ft_putnbr(op.x - op.y);
	else if (op.c == '*')
		ft_putnbr(op.x * op.y);
	else if (op.c == '/')
		ft_putnbr(op.x / op.y);
	else if (op.c == '%')
		ft_putnbr(op.x % op.y);
	else if (op.c == 0)
		ft_putnbr(0);
}

int	main(int argc, char **argv)
{
	t_op	op;

	if (argc == 4)
	{
		op.x = ft_atoi(argv[1]);
		op.c = check_argop(argv[2]);
		op.y = ft_atoi(argv[3]);
		if (!forbiddenop(op))
			do_op(op);
	}
	return (0);
}
