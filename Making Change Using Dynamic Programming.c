
#include <stdio.h>
#define INF 999999

int main() {
    int n, amount, coin[100], dp[10001];
    int i, j;

    printf("Enter number of coin types: ");
    scanf("%d", &n);

    printf("Enter coin values:\n");
    for(i=0; i<n; i++)
        scanf("%d", &coin[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    if(amount < 0 || amount > 10000) {
        printf("Invalid amount");
        return 0;
    }

    dp[0]=0;
    for(i=1; i<=amount; i++)
        dp[i]=INF;

    for(i=1; i<=amount; i++) {
        for(j=0; j<n; j++) {
            if(coin[j]>0 && coin[j]<=i &&
               dp[i-coin[j]]!=INF &&
               dp[i-coin[j]]+1<dp[i])
                dp[i]=dp[i-coin[j]]+1;
        }
    }

    if(dp[amount]==INF)
        printf("Change is not possible");
    else
        printf("Minimum number of coins = %d", dp[amount]);

    return 0;
}

