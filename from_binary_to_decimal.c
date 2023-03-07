/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_binary_to_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:18:03 by zasabri           #+#    #+#             */
/*   Updated: 2023/03/07 20:18:05 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*!CODING_GAME*/

int	check_errors(char *str)
{
	int i = 0;
	while (str[i])
	{
		if ((str[i] != '1' && str[i] != '0') || str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	binary_to_decimal(char *str)
{
	int	l = strlen(str) - 1;
	int base = 1;
	int number = 0;
	while (l >= 0)
	{
		if (str[l] == '1')
			number += base;
		base *= 2;
		l--;
	}
	return (number);
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		int i = 1;
		while (av[i])
		{
			if (check_errors(av[i]))
			{
				printf("Somthing Wrong with this argement: `%s'\n", av[i]);
				if (av[i + 1])
					i++;
				else
					break;
			}
			int k = binary_to_decimal(av[i]);
			printf("%d\n", k);
			i++;
		}
	}
}