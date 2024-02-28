#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, d;
    scanf("%d", &n);
    if (n == 0)
        return (printf("Enter Some NUmber Please!\n"));
    int arr[n], target, times;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d);
        arr[i] = d;
    }
    int check = 0, i = 0, swap;
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (check == 0)
                check = 1;
            swap = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = swap;
            i = -1;
        }
        i++;
    }
    for (int j = 0; j < n; j++)
        printf("%d ", arr[j]);
    printf("\n");
    i = 1;
    int col = 1;
    while (i < n)
    {
        if (arr[i] != arr[i - 1])
        {
            printf("Here number = %d times %d\n", arr[i -1], col);
            if (col >= times)
                times = col, target = arr[i - 1];
            col = 0;
        }
        col++;
        i++;
    }
    if (col >= times)
        times = col, target = arr[i - 1];
    printf("The Number %d Appering %d Times\n", target, times);
}