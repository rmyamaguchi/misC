#include <stdio.h>
#include <stdlib.h>

#define ADDRESS(m, n, arr)                     \
    {                                          \
        for (int _i_ = 0; _i_ < m; _i_++)      \
        {                                      \
            for (int _j_ = 0; _j_ < n; _j_++)  \
                printf("%p|", &arr[_i_][_j_]); \
            printf("\n");                      \
        }                                      \
    }

void func(int m, int n, int arr[][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%2d|", arr[i][j]);
        printf("\n");
    }
    ADDRESS(m, n, arr);
}

int main()
{
    int m = 5;
    int n = 3;
    int(*arr)[n];
    arr = malloc(m * sizeof(*arr));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = i + j;
    ADDRESS(m, n, arr);
    printf(">>>>>>> Call func\n");
    func(m, n, arr);
    free(arr);

    return 0;
}