#include <stdio.h>
void main()
{
    int n, no, mod, cnt;
    int hash[11][2];
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            hash[i][j] = -1;
        }
    }
    printf("Enter the numbers you want to store: ");
    scanf("%d", &n);
    for (int i = 0; i <n; i++)
    {
        cnt = 0;
        scanf("%d", &no);
        mod = no % 11;

        while(1)
        {
            if (hash[mod + cnt][0] == -1)
            {
                hash[mod + cnt][0] = no;
                break;
            }
            else if (hash[mod + cnt][1] == -1)
            {
                hash[mod + cnt][1] = no;
                break;
            }
            cnt++;
        }
    }
    printf("Final hash table: \n");
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", hash[i][j]);
        }
        printf("\n");
    }
}