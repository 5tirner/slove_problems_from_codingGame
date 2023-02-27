/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unary.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:54:36 by zasabri           #+#    #+#             */
/*   Updated: 2023/02/27 16:55:38 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
/*
Here is the encoding principle:

The input message consists of ASCII characters (7-bit)
The encoded output message consists of blocks of 0
A block is separated from another block by a space
Two consecutive blocks are used to produce a series of same value bits (only 1 or 0 values):
- First block: it is always 0 or 00. If it is 0, then the series contains 1, if not, it contains 0
- Second block: the number of 0 in this block is the number of bits in the series
 	Example
Let’s take a simple example with a message which consists of only one character: Capital C. C in binary is represented as 1000011, so with this method, this gives:

0 0 (the first series consists of only a single 1)
00 0000 (the second series consists of four 0)
0 00 (the third consists of two 1)
So C is coded as: 0 0 00 0000 0 00

 
Second example, we want to encode the message CC (i.e. the 14 bits 10000111000011) :

0 0 (one single 1)
00 0000 (four 0)
0 000 (three 1)
00 0000 (four 0)
0 00 (two 1)
So CC is coded as: 0 0 00 0000 0 000 00 0000 0 00*/

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str = malloc((strlen(s1) + strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[k++] = s1[i++];
	while (s2[j])
		str[k++] = s2[j++];
	str[k] = '\0';
	free(s1);
	return (str);
}
char    *binary(int c)
{
    char *str = malloc(8);
    int i = 64;
    int j = 0;
    while (i != 0)
    {
        if (c >= i)
        {
            str[j] = '1';
            c -= i;
        }
        else
            str[j] = '0';
        i/=2;
        j++;
    }
    str[j] = '\0';
    return (str);
}

int main()
{
    char MESSAGE[101];
    scanf("%[^\n]", MESSAGE);
    char *str;
    char *save = malloc(1);
    save[0] = '\0';
    int i = 0;
    while (MESSAGE[i])
    {
        str = binary(MESSAGE[i]);
        save = ft_strjoin(save,str);
        i++;
    }
    i = 0;
    int count = 0;
    while (save[i])
    {
        count = 0;
        if (i!=0)
            printf(" ");
        if (save[i] == '0')
        {
            while (save[i] == '0')
            {
                count++;
                i++;
            }
		if (count == 7)
            printf("00 0000000");
		else if (count == 6)
            printf("00 000000");
		else if (count == 5)
            printf("00 00000");
        else if (count == 4)
            printf("00 0000");
        else if (count == 3)
            printf("00 000");
        else if (count == 2)
            printf("00 00");
        else if (count == 1)
            printf("00 0");
        }
        else if (save[i] == '1')
        {
            while (save[i] == '1')
            {
                count++;
                i++;
            }
		if (count == 7)
            printf("0 0000000");
		else if (count == 6)
            printf("0 000000");
		else if (count == 5)
            printf("0 00000");
        else if (count == 4)
            printf("0 0000");
        else if (count == 3)
            printf("0 000");
        else if (count == 2)
            printf("0 00");
        else if (count == 1)
            printf("0 0");
        }
    }
}