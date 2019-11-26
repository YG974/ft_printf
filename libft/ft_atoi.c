/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:05:18 by ygeslin           #+#    #+#             */
/*   Updated: 2019/11/25 20:15:38 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int pos_nb;
	int sign;
	int messie;

	pos_nb = ft_tnrvfrr(str, "0123456789");
	messie = 0;
	sign = 1;
	if (pos_nb == -1)
		return (0);
	if (str[pos_nb] == '+' || str[pos_nb] == '-')
	{
		if (str[pos_nb] == '-')
			sign = -sign;
		pos_nb++;
	}
	while (str[pos_nb] >= '0' && str[pos_nb] <= '9')
	{
		messie = (messie * 10) + (str[pos_nb] - '0');
		pos_nb++;
	}
	return (messie * sign);
}
