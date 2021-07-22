/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnicolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:44:04 by bnicolas          #+#    #+#             */
/*   Updated: 2021/07/22 14:42:10 by bnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AUX_H
# define FT_AUX_H
# include <unistd.h>
# define BASIC_OP(c) ((c == '+' || c == '-' || c == '*') ? 1 : 0)
# define DIV_OP(c) ((c == '/' || c == '%') ? 1 : 0)
typedef struct s_op{
	int		x;
	char	c;
	int		y;
}t_op;

void	ft_putchar(char c);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
#endif