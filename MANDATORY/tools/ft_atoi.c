/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:02:43 by zogrir            #+#    #+#             */
/*   Updated: 2025/03/15 06:29:50 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	ft_putnbr(int i, long nb, int sign, const char *str)
{
	if (!(str[i] >= '0' && str[i] <= '9'))
		return ((long)INT_MAX + 1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb > 2147483647 && sign == 1)
			return ((long)INT_MAX + 1);
		else if (nb > 2147483648 && sign == -1)
			return ((long)INT_MAX + 1);
		i++;
	}
	if (str[i] != '\0')
		return ((long)INT_MAX + 1);
	return ((int)(nb * sign));
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	nb = ft_putnbr(i, nb, sign, str);
	if (nb == ((long)INT_MAX + 1))
		return (0);
	return ((int)nb);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd == -1 || !s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(1, "\n", 1);
}
