#include <stdio.h>
int binarySearch(int arr[], int low, int high, int target)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            return binarySearch(arr, mid + 1, high, target);
        else
            return binarySearch(arr, low, mid - 1, target);
    }
    return -1;
}
int main()
{
    int n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the sorted elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &target);
    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1)
        printf("Element %d found at index %d.\n", target, index);
    else
        printf("Element %d not found in the array.\n", target);
    return 0;
}