#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
//in this exercice you have to print the strings by the number in the last of them
//input: `n' number of the strings
//output: the strings sorted by the number in the last of any string  
/*example :
input:	n = 4
		test234
		test56
		test67
		test8736

output:	test56
		test67
		test234
		test8736
*/
static size_t	char_count(char const *s, char c)
{
	size_t	index;
	size_t	count_t;

	index = 0;
	count_t = 0;
	while (s[index] && s[index] == c)
		index++;
	while (s[index])
	{
		while (s[index] && s[index] != c)
			index++;
		while (s[index] && s[index] == c)
			index++;
		count_t++;
	}
	return (count_t);
}

static size_t	new_i(char const *s, char c, size_t index)
{
	while (s[index] && s[index] == c)
		index++;
	return (index);
}

static size_t	splittostr(char const *s, char c, char **p)
{
	size_t	index;
	size_t	x;
	size_t	m;
	size_t	count_t;

	index = 0;
	count_t = 0;
	index = new_i(s, c, index);
	while (s[index])
	{
		m = 0;
		x = index;
		while (s[index] && s[index] != c)
			index++;
		p[count_t] = (char *)malloc(index - x + 1);
		if (!p[count_t])
			return (count_t);
		while (x < index)
			p[count_t][m++] = s[x++];
		p[count_t][m] = '\0';
		index = new_i(s, c, index);
		count_t++;
	}
	return (count_t);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	c_c;
	size_t	m;

	if (!s)
		return (NULL);
	c_c = char_count(s, c);
	p = (char **)malloc(sizeof(char *) * (c_c + 1));
	if (!p)
		return (NULL);
	p[c_c] = NULL;
	if (c_c == 0)
		return (p);
	m = splittostr(s, c, p);
	if (m != c_c)
	{
		while (m > 0)
		{
			free (p[m - 1]);
			m--;
		}
		free (p);
		return (NULL);
	}
	return (p);
}

int *sort(int *arr, int size)
{
    int i = 0;
    int s;
    while (i < size-1)
    {
        if (arr[i] > arr[i + 1])
        {
            s = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = s;
            i = 0;
        }
        else
            i++;
    }
    return (arr);
}
int main()
{
    int n;
    scanf("%d", &n); fgetc(stdin);
    char *str = malloc(102 * n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        char desperado[101];
        scanf("%[^\n]", desperado); fgetc(stdin);
        int k = 0;
        while (desperado[k])
        {
            str[j] = desperado[k];
            k++;
            j++;
        }
        str[j] = '\\';
        j++;
    }
    str[j] = '\0';
    char **s = ft_split(str, '\\');
    int i = 0;
    int arr[n];
    while (i < n)
    {
        int k = 0;
        while (s[i][k] && !(isdigit(s[i][k])))
            k++;
        arr[i] = atoi(&s[i][k]);
        i++;
    }
    sort(arr, n);
    i = 0;
    while (i < n)
    {
		int k = 0;
        while (s[k])
		{
			j = 0;
			while (s[k][j] && !(isdigit(s[k][j])))
				j++;
			if (arr[i] == atoi(&s[k][j]))
			{
				printf("%s\n", s[k]);
				break;
			}
			k++;
		}
		i++;
    }
}