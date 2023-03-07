/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_numbres_that_repeat.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:17:57 by zasabri           #+#    #+#             */
/*   Updated: 2023/03/07 20:37:42 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
input s1 and s2(two string)
you have to find the numbers in the two strings and print them in a sorting pattern start (duplicat must appear in the output)
example:
input : s1 = "3 4 5 8 1"
		s2 = "7 9 8 6 11 189 4 1 1 1 1 1 0"
output: 1 1 1 1 1 4 8*/

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int *sort(int *arr, int size)
{
    int i = 0, swap;
    while(i < size - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            swap = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = swap;
            i = 0;
        }
        else
            i++;
    }
	return (arr);
}

int main()
{
    char S1[257];
    scanf("%[^\n]", S1); fgetc(stdin);
    char S2[257];
    scanf("%[^\n]", S2);
    int i = 0,j=0;
    while (S1[i])
    {
        if (S1[i] == ' ')
            j++;
        i++;
    }
	j++;
    int k = j;
    int arr[j];
    i = 0;
    j = 0;
    while (S2[i])
    {
        if (S2[i] == ' ')
            j++;
        i++;
    }
	j++;
    int t = j;
    int arr1[j];
    j = 0;
    i = 0;
    while (S1[i])
    {
        if (isdigit(S1[i]))
        {
            arr[j] = atoi(&S1[i]);
            j++;
            while (isdigit(S1[i]))
                i++;
        }
        i++;
    }
    i = 0;
    j = 0;
    while (S2[i])
    {
        if (isdigit(S2[i]))
        {
            arr1[j] = atoi(&S2[i]);
            j++;
            while (isdigit(S2[i]))
                i++;
        }
        i++;
    }
    int *a = sort(arr, k);
    int *b = sort(arr1, t);
    i = 0;
    j = 0;
    int p = 0;
    while(i <= k)
    {
        j = 0;
        while (j <= t)
        {
            if (arr[i] == arr1[j])
				p++;
            j++;
        }
        i++;
    }
	int res[p];
	i = 0;
	p = 0;
	while(i < k)
    {
        j = 0;
        while (j < t)
        {
            if (arr[i] == arr1[j])
			{
				res[p] = arr[i];
				p++;
			}
            j++;
        }
        i++;
    }
	i = 0;
	sort(res, p);
	while (i < p)
	{
		if (i != 0)
			printf(" ");
		printf("%d", res[i++]);
	}
}