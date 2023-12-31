/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:07:02 by emeinert          #+#    #+#             */
/*   Updated: 2023/03/08 13:46:19 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_intlen(int nb)
{
	long	len;

	len = 0;
	if (nb == 0)
		len = 1;
	else
	{
		while (nb != 0)
		{
			nb = nb / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	len;
	char	*str;
	long	nb;

	nb = (long)n;
	len = ft_intlen(nb);
	if (nb < 0)
	{
		nb = -1 * nb;
		len += 1;
	}
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
	str[len] = (nb % 10) + '0';
	nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
