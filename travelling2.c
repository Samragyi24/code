#include <stdio.h>
#include <limits.h>
#define V 4
void tsp(int graph[V][V])
{
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++)
    {
        for (int j = 0; j < V; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    dp[1][0] = 0;
    for (int mask = 1; mask < (1 << V); mask++)
    {
        for (int i = 0; i < V; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                for (int j = 0; j < V; j++)
                {
                    if ((mask & (1 << j)) != 0 && graph[j][i] && i != j && dp[mask ^ (1 << i)][j] != INT_MAX)
                    {
                        if (dp[mask][i] > dp[mask ^ (1 << i)][j] + graph[j][i])
                        {
                            dp[mask][i] = dp[mask ^ (1 << i)][j] + graph[j][i];
                        }
                    }
                }
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i < V; i++)
    {
        if (graph[i][0])
        {
            ans = ans > dp[(1 << V) - 1][i] + graph[i][0] ? dp[(1 << V) - 1][i] + graph[i][0] : ans;
        }
    }
    printf("Minimum cost required to cover all the cities exactly once: %d\n", ans);
}
int main()
{
    int graph[V][V];
    printf("Enter the adjacency matrix for the graph (4x4):\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    tsp(graph);
    return 0;
}