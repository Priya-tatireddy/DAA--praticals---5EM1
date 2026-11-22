
#include <stdio.h>
#define INF 999999
#define MAX 15

int n, cost[MAX][MAX], dp[1<<MAX][MAX];

int tsp(int mask,int pos) {
    int city,ans=INF,newCost;

    if(mask==(1<<n)-1)
        return cost[pos][0];

    if(dp[mask][pos]!=-1)
        return dp[mask][pos];

    for(city=0;city<n;city++) {
        if(!(mask&(1<<city)) && cost[pos][city]<INF) {
            newCost=cost[pos][city]+
                    tsp(mask|(1<<city),city);

            if(newCost<ans)
                ans=newCost;
        }
    }

    return dp[mask][pos]=ans;
}

int main() {
    int i,j;

    printf("Enter number of cities (maximum 15): ");
    scanf("%d",&n);

    if(n<2 || n>MAX) {
        printf("Invalid number of cities");
        return 0;
    }

    printf("Enter cost matrix (999999 for no route):\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);

    for(i=0;i<(1<<n);i++)
        for(j=0;j<n;j++)
            dp[i][j]=-1;

    int answer=tsp(1,0);

    if(answer>=INF)
        printf("Tour is not possible");
    else
        printf("Minimum travelling cost = %d",answer);

    return 0;
}

