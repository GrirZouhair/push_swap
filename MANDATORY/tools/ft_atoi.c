/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:02:43 by zogrir            #+#    #+#             */
/*   Updated: 2025/03/06 15:53:48 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static int	ft_putnbr(int i, long nb, int sign, const char *str)
{
	if (!(str[i] >= '0' && str[i] <= '9'))
	{
		ft_putstr_fd("\033[1;31m🛑ERROR: Invalid input\033[0m\n", 2);
		exit(1);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb > 2147483647 && sign == 1)
		{
			ft_putstr_fd("\033[1;31m🛑ERROR: Integer overflow\033[0m\n", 2);
			exit(1);
		}
		else if (nb > 2147483648 && sign == -1)
		{
			ft_putstr_fd("\033[1;31m🛑ERROR: Integer overflow\033[0m\n", 2);
			exit(1);
		}
		i++;
	}
	if (str[i] != '\0')
	{
		ft_putstr_fd("\033[1;31m🛑ERROR: Invalid characters in input\033[0m\n", 2);
		exit(1);
	}
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
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) // Skip whitespace
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	return (ft_putnbr(i, nb, sign, str));
}


void	ft_putstr_fd(char *s, int fd)
{
	if (fd == -1 || !s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(1, "\n", 1);
}
