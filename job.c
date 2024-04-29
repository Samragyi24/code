#include <stdio.h>
#include <stdlib.h>
struct Job
{
    char id;
    int deadline;
    int profit;
};
int compare(const void *a, const void *b)
{
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}
void jobSequencing(struct Job jobs[], int n)
{
    qsort(jobs, n, sizeof(jobs[0]), compare);
    int result[n];
    char slot[n];
    for (int i = 0; i < n; i++)
        slot[i] = '0';
    for (int i = 0; i < n; i++)
    {
        for (int j = (jobs[i].deadline < n) ? jobs[i].deadline - 1 : n - 1; j >= 0; j--)
        {
            if (slot[j] == '0')
            {
                result[j] = i;
                slot[j] = '1';
                break;
            }
        }
    }
    printf("The sequence of jobs with maximum profit is:\n");
    for (int i = 0; i < n; i++)
    {
        if (slot[i] == '1')
            printf("%c ", jobs[result[i]].id);
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct Job jobs[n];
    printf("Enter the details of each job (ID, Deadline, Profit):\n");
    for (int i = 0; i < n; i++)
    {
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    jobSequencing(jobs, n);
    return 0;
}