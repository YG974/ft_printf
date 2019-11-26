/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:03:22 by ygeslin           #+#    #+#             */
/*   Updated: 2019/11/25 20:10:46 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	len_base;
	int				pos_nb;
	int				sign;
	int				messie;

	len_base = ft_strlen_strstr(base);
	if (len_base < 2)
		return (0);
	pos_nb = ft_tnrvfrr(str, base);
	messie = 0;
	sign = 1;
	if (pos_nb == -1)
		return (0);
	while (str[pos_nb] == '+' || str[pos_nb] == '-')
	{
		if (str[pos_nb] == '-')
			sign = -sign;
		pos_nb++;
	}
	while (base_index(str[pos_nb], base) >= 0)
	{
		messie = (messie * len_base) + base_index(str[pos_nb], base);
		pos_nb++;
	}
	return (messie * sign);
}
