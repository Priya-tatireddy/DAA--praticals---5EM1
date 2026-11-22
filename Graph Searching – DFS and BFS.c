
#include <stdio.h>

int a[20][20], visited[20], n;

void DFS(int v) {
    int i;
    visited[v]=1;
    printf("%d ",v);

    for(i=0;i<n;i++) {
        if(a[v][i]==1 && !visited[i])
            DFS(i);
    }
}

void BFS(int start) {
    int q[20], front=0, rear=0, i, v;
    for(i=0;i<n;i++) visited[i]=0;

    visited[start]=1;
    q[rear++]=start;

    while(front<rear) {
        v=q[front++];
        printf("%d ",v);

        for(i=0;i<n;i++) {
            if(a[v][i]==1 && !visited[i]) {
                visited[i]=1;
                q[rear++]=i;
            }
        }
    }
}

int main() {
    int i,j,start;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    if(n<1 || n>20 || start<0 || start>=n) {
        printf("Invalid input");
        return 0;
    }

    for(i=0;i<n;i++) visited[i]=0;
    printf("DFS Traversal: ");
    DFS(start);

    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}

