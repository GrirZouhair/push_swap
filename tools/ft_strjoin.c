/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zogrir <zogrir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 09:12:48 by zogrir            #+#    #+#             */
/*   Updated: 2025/01/22 11:31:24 by zogrir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ft_putstr_fd(char *s, int fd)
{
	if (fd == -1 || !s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(1, "\n", 1);	
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*destination;
	unsigned char		*source;
	unsigned int		i;

	i = 0;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst || !src)
		return (NULL);
	while (n > 0)
	{
		destination[i] = source[i];
		i++;
		n--;
	}
	return (dst);
}

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int calculate_length(int size, char **strs, int i)
{
	int len;

	if (i == size)
		return (0);

	len = ft_strlen(strs[i]);
	if (i < size - 1)
		len += 1;
	return (len + calculate_length(size, strs, i + 1));
}

void join_strings(int size, char **strs, char sep, int i, char *args, int *pos)
{
	if (i == size)
		return ;

	int len = ft_strlen(strs[i]);
	ft_memcpy(args + *pos, strs[i], len);
	*pos += len;

	if (i < size - 1)
	{
		args[*pos] = sep;
		(*pos)++;
	}

	join_strings(size, strs, sep, i + 1, args, pos);
}

char *ft_strjoin(int size, char **strs, char sep)
{
	char	*args;
	int		total_len;
	int 	pos;

	pos = 0;
	total_len = 0;
	if (size <= 0)
	{
		args = malloc(1);	
		args[0] = '\0';
		return (args);
	}

	total_len = calculate_length(size, strs, 0);
	args = malloc(total_len + 1);
	if (!args)
		return (free(args), NULL);

	join_strings(size, strs, sep, 0, args, &pos);
	args[pos] = '\0';
	return (args);
}

/*
#include<stdio.h> 
int main()
{
    
    char *strs[] = {"zouhair", "amine", "salah", "bla", "bla"};
    int size = 5;
    char sep = ' ';

    char *result = ft_strjoin(size, strs, sep);

    printf("Joined string: %s\n", result);
    free(result);
	

    return 0;
}
*/