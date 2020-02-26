/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:28:37 by ygeslin           #+#    #+#             */
/*   Updated: 2019/10/22 16:19:30 by ygeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *ptr, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)ptr;
	while (n > 0)
	{
		tmp[n - 1] = '\0';
		n--;
	}
}