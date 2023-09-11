#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    string message;
    getline(cin, message);
    size_t i = message.length();
    int s = sqrt(i);
    char **str = (char **)malloc(sizeof(char *) * (s + 1));
    int j = 0;
    int t = 0;
    while (message[j])
    {
        int k = 0;
        str[t] = (char *)malloc(s + 1);
        while (message[j] && k < s)
        {
            str[t][k] = message[j];
            j++;
            k++;
        }
        str[t][k] = '\0';
        t++;
    }
    str[t] = 0;
    j = 0;
    i = 0;
    while (str[i][j])
    {
        int k = 0;
        while (str[k])
        {
		if(str[k][j])
            		printf("%c", str[k][j]);
           	 k++;
        }
        j++;
    }
}
