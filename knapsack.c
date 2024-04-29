#include <stdio.h>
#include <stdlib.h>
struct Item
{
    int value;
    int weight;
};
int compare(const void *a, const void *b)
{
    struct Item item1 = *(struct Item *)a;
    struct Item item2 = *(struct Item *)b;
    double ratio1 = (double)item1.value / item1.weight;
    double ratio2 = (double)item2.value / item2.weight;
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}
double fractionalKnapsack(struct Item items[], int n, int capacity)
{
    qsort(items, n, sizeof(items[0]), compare);
    double totalValue = 0.0;
    int currentWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        }
        else
        {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }
    return totalValue;
}
int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);
    struct Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    double totalValue = fractionalKnapsack(items, n, capacity);
    printf("The maximum value in the knapsack is: %.2lf\n", totalValue);
    return 0;
}