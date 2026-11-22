
#include <stdio.h>
#define INF 99999

int main() {
    int a[20][20],n,i,j,k;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    if(n<1 || n>20) {
        printf("Invalid input");
        return 0;
    }

    printf("Enter cost matrix (99999 for no edge):\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    for(k=0;k<n;k++) {
        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                if(a[i][k]!=INF && a[k][j]!=INF &&
                   a[i][k]+a[k][j]<a[i][j])
                    a[i][j]=a[i][k]+a[k][j];
            }
        }
    }

    printf("Shortest distance matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            if(a[i][j]==INF)
                printf("INF ");
            else
                printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

