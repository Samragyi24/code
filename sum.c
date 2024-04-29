#include <stdio.h>
void findPairON2(int arr[], int n, int sum)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                printf("Pair found: %d + %d = %d\n", arr[i], arr[j], sum);
                return;
            }
        }
    }
    printf("Pair not found\n");
}
void findPairON(int arr[], int n, int sum)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == sum)
        {
            printf("Pair found: %d + %d = %d\n", arr[low], arr[high], sum);
            return;
        }
        else if (arr[low] + arr[high] < sum)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    printf("Pair not found\n");
}
int main()
{
    int n, sum;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the sorted array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the sum you want to find: ");
    scanf("%d", &sum);
    printf("\nUsing O(n^2) solution:\n");
    findPairON2(arr, n, sum);
    printf("\nUsing O(n) solution:\n");
    findPairON(arr, n, sum);
    return 0;
}