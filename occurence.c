#include <stdio.h>
int countOccurrencesON(int arr[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            count++;
        else if (arr[i] > x)
            break;
    }
    return count;
}
int countOccurrencesOLOGN(int arr[], int n, int x)
{
    int firstIndex = -1;
    int lastIndex = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            firstIndex = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            lastIndex = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (firstIndex == -1)
        return 0;
    else
        return (lastIndex - firstIndex + 1);
}
int main()
{
    int n, x;
    printf("Enter the size of the sorted array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the sorted array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to find occurrences: ");
    scanf("%d", &x);
    printf("\nOccurrences of %d (O(n) solution): %d\n", x, countOccurrencesON(arr, n, x));
    printf("Occurrences of %d (O(log n) solution): %d\n", x, countOccurrencesOLOGN(arr, n, x));
    return 0;
}